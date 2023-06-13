#include<iostream>
using namespace std;
typedef struct PNode
{
	float coef;
	int expn;
	struct PNode* next;
}PNode, * polynomial;
void display();
void createpolyn(polynomial& p);
void add_polynomial(polynomial& pa, polynomial& pb);
void subtruct_polynomial(polynomial& p1, polynomial& p2);
void multiply_polynomial(polynomial& p1, polynomial& p2);
void printout(const polynomial& p);
int main() {
	int n;
	polynomial p1 = new PNode;	//为链表P1申请一个空间;
	polynomial p2 = new PNode;	//为链表P2申请一个空间;
	display();
	while (true) {
		cout << "请输入要执行的操作：";
		cin >> n;
		switch (n) {
		case 1:
			createpolyn(p1);
			cout << "第一个多项式为：";
			printout(p1);
			cout << endl;
			createpolyn(p2);
			cout << "第二个多项式为：";
			printout(p2);
			cout << endl;
			break;
		case 2:
			//多项式相加
			add_polynomial(p1, p2);
			cout << endl;
			break;
		case 3:
			//多项式减法
			subtruct_polynomial(p1, p2);
			cout << endl;
			break;
		case 4:
			//多项式相乘
			multiply_polynomial(p1, p2);
			cout << endl;
			break;
		case 0:
			exit(1);
		default:
			cout << "输入不合法，请重新输入！" << endl;
			cout << endl;
			break;
		}
	}
	return 0;
}

void display()
{
	cout << "**********多项式的加减乘法**********" << endl;
	cout << "1.输入多项式" << endl;
	cout << "2.多项式相加" << endl;
	cout << "3.多项式相减" << endl;
	cout << "4.多项式相乘" << endl;
	cout << "0.退出" << endl;
	cout << "************************************" << endl;
}

void createpolyn(polynomial& p)
{
	p = new PNode;
	p->next = NULL;
	int n;
	cout << "请输入多项式的项数：";
	cin >> n;
	polynomial pre;
	polynomial q;
	for (int i = 1; i <= n; i++)
	{
		polynomial s = new PNode;
		cout << "请输入第" << i << "项的系数和指数：";
		cin >> s->coef >> s->expn;
		pre = p;
		q = p->next;
		while (q && q->expn < s->expn)
		{
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;
	}	
}

void printout(const polynomial& p)
{
	polynomial current = p->next;
	bool isFirstTerm = true;  //标识当前是否是第一个非零项

	while (current) {
		int coef = current->coef;
		int expn = current->expn;

		if (coef != 0) {
			if (!isFirstTerm && coef > 0) { //用在打印 "+" 符号之前，如果是第一个非零项，不需要打印 "+
				cout << "+";
			}

			if (expn == 0) {
				cout << coef;
			}
			else {   //输出系数
				if (coef != 1 && coef != -1) {
					cout << coef;
				}
				else if (coef == -1) {
					cout << "-";
				}

				if (expn == 1) {  //输出指数
					cout << "x";
				}
				else {
					cout << "x^" << expn;
				}
			}

			isFirstTerm = false;
		}

		current = current->next;
	}

	if (isFirstTerm) {
		cout << "0";
	}

	cout << endl;
}

void add_polynomial(polynomial& pa, polynomial& pb)
{
	polynomial p1 = pa->next;
	polynomial p2 = pb->next;
	polynomial result = new PNode; //创建新的多项式来保存结果
	result->next = nullptr;
	polynomial p3 = result; // p3用于指向结果多项式的最后一个节点

	while (p1 && p2) {
		if (p1->expn == p2->expn)
		{
			int sum;
			sum = p1->coef + p2->coef;
			if (sum != 0)
			{
				polynomial r = new PNode;
				r->coef = sum;
				r->expn = p1->expn;
				r->next = nullptr;
				p3->next = r;
				p3 = r;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->expn < p2->expn) {
			polynomial r = new PNode;
			r->coef = p1->coef;
			r->expn = p1->expn;
			r->next = nullptr;
			p3->next = r;
			p3 = r;
			p1 = p1->next;
		}
		else {
			polynomial r = new PNode;
			r->coef = p2->coef;
			r->expn = p2->expn;
			r->next = nullptr;
			p3->next = r;
			p3 = r;
			p2 = p2->next;
		}
	}

	while (p1) {
		polynomial r = new PNode;
		r->coef = p1->coef;
		r->expn = p1->expn;
		r->next = nullptr;
		p3->next = r;
		p3 = r;
		p1 = p1->next;
	}

	while (p2) {
		polynomial r = new PNode;
		r->coef = p2->coef;
		r->expn = p2->expn;
		r->next = nullptr;
		p3->next = r;
		p3 = r;
		p2 = p2->next;
	}

	cout << "相加的结果为：" << endl;
	printout(result);	//输出结果
}

void subtruct_polynomial(polynomial& pa, polynomial& pb)
{
	polynomial p1 = pa->next;
	polynomial p2 = pb->next;
	polynomial result = new PNode; //创建新的多项式来保存结果
	result->next = nullptr;
	polynomial p3 = result; // p3用于指向结果多项式的最后一个节点

	while (p1 && p2) {
		if (p1->expn == p2->expn) {
			int diff = p1->coef - p2->coef;
			if (diff != 0) {
				polynomial r = new PNode;
				r->coef = diff;
				r->expn = p1->expn;
				r->next = nullptr;
				p3->next = r;
				p3 = r;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->expn < p2->expn) {
			polynomial r = new PNode;
			r->coef = p1->coef;
			r->expn = p1->expn;
			r->next = nullptr;
			p3->next = r;
			p3 = r;
			p1 = p1->next;
		}
		else {
			polynomial r = new PNode;
			r->coef = -p2->coef;
			r->expn = p2->expn;
			r->next = nullptr;
			p3->next = r;
			p3 = r;
			p2 = p2->next;
		}
	}

	while (p1) {
		polynomial r = new PNode;
		r->coef = p1->coef;
		r->expn = p1->expn;
		r->next = nullptr;
		p3->next = r;
		p3 = r;
		p1 = p1->next;
	}

	while (p2) {
		polynomial r = new PNode;
		r->coef = -p2->coef;
		r->expn = p2->expn;
		r->next = nullptr;
		p3->next = r;
		p3 = r;
		p2 = p2->next;
	}

	cout << "相减的结果为：" << endl;
	printout(result); //输出结果
}

void multiply_polynomial(polynomial& pa, polynomial& pb)
{
	polynomial p1 = pa->next;
	polynomial p2 = pb->next;
	polynomial result = new PNode; //创建新的多项式来保存结果
	result->next = nullptr;

	while (p1) {
		polynomial tempP2 = p2;
		while (tempP2) {
			// 创建一个新节点，保存 p1 项和 p2 项的乘积
			polynomial r = new PNode;
			r->coef = p1->coef * tempP2->coef;
			r->expn = p1->expn + tempP2->expn;
			r->next = nullptr;

			// 将新节点插入到结果多项式中，按照指数的顺序插入
			polynomial pre = result;
			polynomial cur = result->next;
			while (cur && cur->expn < r->expn) {
				pre = cur;
				cur = cur->next;
			}
			if (cur && cur->expn == r->expn) {
				// 如果结果多项式中已经有了相同指数的项，则将它们的系数相加
				cur->coef += r->coef;
				delete r;
			}
			else {
				// 否则，将新节点插入到正确的位置
				r->next = cur;
				pre->next = r;
			}

			tempP2 = tempP2->next;
		}
		p1 = p1->next;
	}

	cout << "相乘的结果为：" << endl;
	printout(result); //输出结果
}