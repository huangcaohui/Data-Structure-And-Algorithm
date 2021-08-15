/*笔记与图见4.2 栈与递归*/

#include <iostream>
#include <stack>

using namespace std;

typedef struct elem{
    int rd, pn, pf, q1, q2;
}ELEM;

class nonrec
{
private:
    stack <ELEM> S;

public:
    nonrec(void){};
    void replace1(int n, int &f);
};

void nonrec::replace1(int n, int &f)
{
    ELEM x, tmp;
    x.rd = 3;
    x.pn = n;

    S.push(x);  //压在栈底作“监视哨”

    label0:
        if((x = S.top()).pn < 2)
        {
            S.pop();
            x.pf = x.pn + 1;
            S.push(x);
            goto label3;
        }

    x.rd = 1;
    x.pn = (int)(x.pn/2);
    S.push(x);
    goto label0;
    label1:
        tmp = S.top();
        S.pop();
        x = S.top();
        S.pop();
        x.q1 = tmp.pf;  //修改u1=pf
        S.push(x);

    x.pn = (int)(x.pn/4);
    x.rd = 2;
    S.push(x);
    goto label0;
    label2:
        tmp = S.top();
        S.pop();
        x = S.top();
        S.pop();
        x.q2 = tmp.pf;
        x.pf = x.q1 * x.q2;
        S.push(x);

    label3:
        x = S.top();
        switch(x.rd)
        {
            case 1:goto label1; break;
            case 2:goto label2; break;
            case 3:tmp = S.top(); S.pop();
                   f = tmp.pf;  //计算结束
                   break;
            default:cerr << "error label number in stack"; break;
        }
}