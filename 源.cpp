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
	polynomial p1 = new PNode;	//Ϊ����P1����һ���ռ�;
	polynomial p2 = new PNode;	//Ϊ����P2����һ���ռ�;
	display();
	while (true) {
		cout << "������Ҫִ�еĲ�����";
		cin >> n;
		switch (n) {
		case 1:
			createpolyn(p1);
			cout << "��һ������ʽΪ��";
			printout(p1);
			cout << endl;
			createpolyn(p2);
			cout << "�ڶ�������ʽΪ��";
			printout(p2);
			cout << endl;
			break;
		case 2:
			//����ʽ���
			add_polynomial(p1, p2);
			cout << endl;
			break;
		case 3:
			//����ʽ����
			subtruct_polynomial(p1, p2);
			cout << endl;
			break;
		case 4:
			//����ʽ���
			multiply_polynomial(p1, p2);
			cout << endl;
			break;
		case 0:
			exit(1);
		default:
			cout << "���벻�Ϸ������������룡" << endl;
			cout << endl;
			break;
		}
	}
	return 0;
}

void display()
{
	cout << "**********����ʽ�ļӼ��˷�**********" << endl;
	cout << "1.�������ʽ" << endl;
	cout << "2.����ʽ���" << endl;
	cout << "3.����ʽ���" << endl;
	cout << "4.����ʽ���" << endl;
	cout << "0.�˳�" << endl;
	cout << "************************************" << endl;
}

void createpolyn(polynomial& p)
{
	p = new PNode;
	p->next = NULL;
	int n;
	cout << "���������ʽ��������";
	cin >> n;
	polynomial pre;
	polynomial q;
	for (int i = 1; i <= n; i++)
	{
		polynomial s = new PNode;
		cout << "�������" << i << "���ϵ����ָ����";
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
	bool isFirstTerm = true;  //��ʶ��ǰ�Ƿ��ǵ�һ��������

	while (current) {
		int coef = current->coef;
		int expn = current->expn;

		if (coef != 0) {
			if (!isFirstTerm && coef > 0) { //���ڴ�ӡ "+" ����֮ǰ������ǵ�һ�����������Ҫ��ӡ "+
				cout << "+";
			}

			if (expn == 0) {
				cout << coef;
			}
			else {   //���ϵ��
				if (coef != 1 && coef != -1) {
					cout << coef;
				}
				else if (coef == -1) {
					cout << "-";
				}

				if (expn == 1) {  //���ָ��
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
	polynomial result = new PNode; //�����µĶ���ʽ��������
	result->next = nullptr;
	polynomial p3 = result; // p3����ָ��������ʽ�����һ���ڵ�

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

	cout << "��ӵĽ��Ϊ��" << endl;
	printout(result);	//������
}

void subtruct_polynomial(polynomial& pa, polynomial& pb)
{
	polynomial p1 = pa->next;
	polynomial p2 = pb->next;
	polynomial result = new PNode; //�����µĶ���ʽ��������
	result->next = nullptr;
	polynomial p3 = result; // p3����ָ��������ʽ�����һ���ڵ�

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

	cout << "����Ľ��Ϊ��" << endl;
	printout(result); //������
}

void multiply_polynomial(polynomial& pa, polynomial& pb)
{
	polynomial p1 = pa->next;
	polynomial p2 = pb->next;
	polynomial result = new PNode; //�����µĶ���ʽ��������
	result->next = nullptr;

	while (p1) {
		polynomial tempP2 = p2;
		while (tempP2) {
			// ����һ���½ڵ㣬���� p1 ��� p2 ��ĳ˻�
			polynomial r = new PNode;
			r->coef = p1->coef * tempP2->coef;
			r->expn = p1->expn + tempP2->expn;
			r->next = nullptr;

			// ���½ڵ���뵽�������ʽ�У�����ָ����˳�����
			polynomial pre = result;
			polynomial cur = result->next;
			while (cur && cur->expn < r->expn) {
				pre = cur;
				cur = cur->next;
			}
			if (cur && cur->expn == r->expn) {
				// ����������ʽ���Ѿ�������ָͬ����������ǵ�ϵ�����
				cur->coef += r->coef;
				delete r;
			}
			else {
				// ���򣬽��½ڵ���뵽��ȷ��λ��
				r->next = cur;
				pre->next = r;
			}

			tempP2 = tempP2->next;
		}
		p1 = p1->next;
	}

	cout << "��˵Ľ��Ϊ��" << endl;
	printout(result); //������
}