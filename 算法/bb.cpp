#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//��Ʒ
typedef struct goods {
	int item;		//��Ʒ����
	int weight;		//����
	int value;		//��ֵ
	int ave;		//ƽ����ֵ=��ֵ/����
};

//��������أ����ȶ��н�������
typedef struct temp {
	bool operator()(goods a, goods b) {
		return a.ave < b.ave;
	}
};

priority_queue < goods, vector<goods>, temp> q;

void Knapsack(int W) {
	vector<bool> choose(q.size() + 1, false);	//��Ʒ�Ƿ�ѡ����뱳��
	int ub = q.top().ave*W;				//��ʼ���Ͻ�
	int w = 0, v = 0;		//��ǰ�����������w����ֵv
	while (!q.empty()){
		if (w + q.top().weight > W) {
			q.pop();
			if (!q.empty())
				ub = v + q.top().ave*(W - w);
			continue;
		}
		goods a = q.top();	//ȡ������λ�õ���Ʒ
		q.pop();
		if (!q.empty()) {
			int yes = v + a.value + q.top().ave*(W - w - a.weight);	//������Ʒ
			int no = v + q.top().ave*(W - w);	//������Ʒ
			if (yes > no) {
				ub = yes;
				w += a.weight;
				v += a.value;
				choose[a.item] = true;
			}
			else 
				ub = no;
		}
		else {
			v += a.value;
			choose[a.item] = true;
		}
	} 
	
	cout << "��������ֵΪ��" << v << endl;
	cout << "װ�����Ʒ���Ϊ��";
	for (int i = 1; i < choose.size(); i++)
		if (choose[i])
			cout << i << " ";
	cout << endl;
}

int main() {
	int n, W;
	cout << "������Ʒ������";
	cin >> n;
	cout << "���뱳��������";
	cin >> W;
	vector<goods> package(n);
	
	cout << "������Ʒ��Ϣ��������w ��ֵw��" << endl;
	for (int i = 0; i < n; i++) {
		package[i].item = i + 1;
		cin >> package[i].weight >> package[i].value;
		package[i].ave = package[i].value / package[i].weight;
		q.push(package[i]);		//������Ϣ���
	}

	Knapsack(W);	//01����

	system("pause");
	return 0;
}
