#ifndef SOURCE
#define SOURCE

#define CARD_X_OFFSET 6	// ī�� �̵� ���� Ŀ�� offset ��
#define CARD_Y_OFFSET 5	// ī�� �̵� ���� Ŀ�� offset ��
#define OPEN 0		// ī�� ���� Ȯ�� ���
#define CLOSE 1		// ī�� Ŭ���� Ȯ�� ���
#define TRUE 1		// TRUE
#define FALSE 0		// FALSE

enum SHAPE {	// �� ����� ��Ÿ���� enum
	SPADES = 0,
	HEARTS,
	DIAMONDS,
	CLUBS
};

struct Card {		// ī���� ������ ������ ����ü
	char number;	// ī���� ����
	char* shape;	// ī���� ���
	char* name;		// ī���� ��� �̸�
};
typedef struct Card Card;

struct Deck {		// ���� ������ ������ ����ü
	Card cards[52];	// ī�� 52��
	int count;		// ���� �� ���� ī�带 open �ߴ��� Ȯ���ϴ� ����
};
typedef struct Deck Deck;

struct Person {
	char name[16];	// ������ �̸�
	float money;		// �����ڰ� ������ �ִ� ��
};
typedef struct Person Person;

struct Gamer {		// Gamer ����
	Person person;	// ��� ����
	Card cards[9];	// 9���� ī�� ����
	float bet_money;	// ���� �ݾ��� �����ϴ� ����
	int num;		// ī�� ������ ��Ÿ���� ����
	int sum[2];		// ī�� ���� ��Ÿ���� ���� 2���� ������ "A"�� ���� ó���� �ϱ� ����
	int hasA;		// A�� �������� �Ǵ��ϴ� ����
	int isLose;		// ������ �Ǵ��ϴ� ����
	int isBlackJack; // �������� �Ǵ��ϴ� ����
	int isStop;		// ī�� ������ ���� ������ Ȯ���ϴ� ����
};
typedef struct Gamer Gamer;

struct Dealer {		// Dealer ����
	Gamer gamer;	// Gamer Ư¡ ����
	int remember[13];	// ī�� ���� ���� ��� ����
};
typedef struct Dealer Dealer;

void setInit(Dealer* dealer, Gamer* player1, Gamer* player2);	// �� �������� game�� �ʿ��� ������ �ʱ�ȭ�ϴ� �Լ�
void clearData(Dealer* dealer, Gamer* player1, Gamer* player2);	// �� �������� �޸𸮸� 0���� �ʱ�ȭ�ϴ� �Լ�
char int_to_cardNumber(int number);	 // �Էµ� ���ڸ� ������ ī�� �ѹ��� �ٲٴ� �Լ�
char cardNumber_to_int(char number); // �Էµ� ī�� �ѹ��� ���� ���ڷ� �ٲٴ� �Լ�
void filldeck(Deck* deck); // �� ����
void betting(Gamer* player);	// ���ñݾ� �Է� �ޱ�
void calCardSum(Gamer* gamer); // ī�� �� ���
void input_player(Gamer* gamer);	// gamer�� �̸��� ���� �Է� �޴� �Լ�
int choiceAction(Gamer* player);	// ī�带 �������� ���� �Լ�
void remember_dealer(Dealer* dealer, Card card);	// ������ ī�带 ����ϴ� �Լ�
int expect_dealer(Dealer* dealer);		// ������ ������ �ϴ� �Լ�
int result_sum(Gamer* gamer);		// ���̸Ӱ� ���� ī�� ���� ��ȯ�ϴ� �Լ�

#endif // !SOURCE
