#include <iostream>
#include <random>
#include <thread>
#include <windows.h>

using namespace std;

bool _1left_2right = true; //������ 1
bool _2left_3right = true; //������ 2
bool _3left_4right = true; //������ 3
bool _4left_5right = true; //������ 4
bool _5left_1right = true; //������ 5

random_device rd; //���� �� �ʱ�ȭ
mt19937 gen(rd());

void thinking(int id) {
	uniform_int_distribution<int> dis(1, 5); //1���� 5���� �����ϰ� ���� dis(gen)�� ��� ����
	int time;

	time = 0; //�������� ����
	printf("[%d] %ds thinking\n", id, time);
	for (int i = 0; i < time; ++i) {
		Sleep(1000); //Sleep(1000) == 1��
	}
	printf("[%d] %ds thinking finish\n", id, time);
}

void eating(int id) {
	uniform_int_distribution<int> dis(1, 5); //1���� 5���� �����ϰ� ���� dis(gen)�� ��� ����
	int time;

	time = 0; //�������� ����
	printf("[%d] %ds eating\n", id, time);
	for (int i = 0; i < time; ++i) {
		Sleep(1000); //Sleep(1000) == 1��
	}
	printf("[%d] %ds eating finish\n", id, time);
}

void func1() {
	int id = 1; //ö���� 1
	while (1) {
		thinking(id);

		while (1) {
			if (_1left_2right) {
				_1left_2right = false;
				break;
			}
		}
		printf("[%d] put on the left chopstick\n", id);
		while (1) {
			if (_5left_1right) {
				_5left_1right = false;
				break;
			}
		}
		printf("[%d] put on the right chopstick\n", id);
		
		eating(id);
		_5left_1right = true;
		printf("[%d] put down the right chopstick\n", id);
		_1left_2right = true;
		printf("[%d] put down the left chopstick\n", id);
	}
}

void func2() {
	int id = 2; //ö���� 2
	while (1) {
		thinking(id);

		while (1) {
			if (_2left_3right) {
				_2left_3right = false;
				break;
			}
		}
		printf("[%d] put on the left chopstick\n", id);
		while (1) {
			if (_1left_2right) {
				_1left_2right = false;
				break;
			}
		}
		printf("[%d] put on the right chopstick\n", id);

		eating(id);
		_1left_2right = true;
		printf("[%d] put down the right chopstick\n", id);
		_2left_3right = true;
		printf("[%d] put down the left chopstick\n", id);
	}
}

void func3() {
	int id = 3; //ö���� 3
	while (1) {
		thinking(id);

		while (1) {
			if (_3left_4right) {
				_3left_4right = false;
				break;
			}
		}
		printf("[%d] put on the left chopstick\n", id);
		while (1) {
			if (_2left_3right) {
				_2left_3right = false;
				break;
			}
		}
		printf("[%d] put on the right chopstick\n", id);
		
		eating(id);
		_2left_3right = true;
		printf("[%d] put down the right chopstick\n", id);
		_3left_4right = true;
		printf("[%d] put down the left chopstick\n", id);
	}	
}

void func4() {
	int id = 4; //ö���� 4
	while (1) {
		thinking(id);

		while (1) {
			if (_4left_5right) {
				_4left_5right = false;
				break;
			}
		}
		printf("[%d] put on the left chopstick\n", id);
		while (1) {
			if (_3left_4right) {
				_3left_4right = false;
				break;
			}
		}
		printf("[%d] put on the right chopstick\n", id);
		
		eating(id);
		_3left_4right = true;
		printf("[%d] put down the right chopstick\n", id);
		_4left_5right = true;
		printf("[%d] put down the left chopstick\n", id);
	}
}

void func5() {
	int id = 5; //ö���� 5
	while (1){
		thinking(id);

		while (1) {
			if (_5left_1right) {
				_5left_1right = false;
				break;
			}
		}
		printf("[%d] put on the left chopstick\n", id);
		while (1) {
			if (_4left_5right) {
				_4left_5right = false;
				break;
			}
		}
		printf("[%d] put on the right chopstick\n", id);
		
		eating(id);
		_4left_5right = true;
		printf("[%d] put down the right chopstick\n", id);
		_5left_1right = true;
		printf("[%d] put down the left chopstick\n", id);
	}
}

int main() {
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);
	thread t4(func4);
	thread t5(func5);
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	return 0;
}