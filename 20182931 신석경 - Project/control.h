#ifndef CONTROL
#define CONTROL

int gameStartOption();	// ���� ������ ���� �Լ�
int gameContinueOption();	// ������ ������� ���� �Լ�
void shuffle(Deck* deck);	// �� ����
void mainControl(Deck* deck, Dealer* dealer, Gamer* player1, Gamer* player2);	// ���� ���� ��Ʈ�� �Լ�
void compare(Dealer* dealer, Gamer* player1, Gamer* player2);		// �� ������ ������ ī�� �� ���Ͽ� ���ڸ� �����ϴ� �Լ�
#endif // !CONTROL
