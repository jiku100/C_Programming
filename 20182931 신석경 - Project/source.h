#ifndef SOURCE
#define SOURCE

#define CARD_X_OFFSET 6	// 카드 이동 관련 커서 offset 값
#define CARD_Y_OFFSET 5	// 카드 이동 관련 커서 offset 값
#define OPEN 0		// 카드 오픈 확인 상수
#define CLOSE 1		// 카드 클로즈 확인 상수
#define TRUE 1		// TRUE
#define FALSE 0		// FALSE

enum SHAPE {	// 각 모양을 나타내는 enum
	SPADES = 0,
	HEARTS,
	DIAMONDS,
	CLUBS
};

struct Card {		// 카드의 정보를 가지는 구조체
	char number;	// 카드의 숫자
	char* shape;	// 카드의 모양
	char* name;		// 카드의 모양 이름
};
typedef struct Card Card;

struct Deck {		// 덱의 정보를 가지는 구조체
	Card cards[52];	// 카드 52장
	int count;		// 현재 몇 장의 카드를 open 했는지 확인하는 변수
};
typedef struct Deck Deck;

struct Person {
	char name[16];	// 참가자 이름
	float money;		// 참가자가 가지고 있는 돈
};
typedef struct Person Person;

struct Gamer {		// Gamer 정의
	Person person;	// 사람 정의
	Card cards[9];	// 9개의 카드 저장
	float bet_money;	// 베팅 금액을 저장하는 변수
	int num;		// 카드 개수를 나타내는 변수
	int sum[2];		// 카드 합을 나타내는 변수 2개인 이유는 "A"에 대한 처리를 하기 위함
	int hasA;		// A를 가졌는지 판단하는 변수
	int isLose;		// 졌는지 판단하는 변수
	int isBlackJack; // 블랙잭인지 판단하는 변수
	int isStop;		// 카드 오픈을 멈출 것인지 확인하는 변수
};
typedef struct Gamer Gamer;

struct Dealer {		// Dealer 정의
	Gamer gamer;	// Gamer 특징 가짐
	int remember[13];	// 카드 오픈 개수 기억 변수
};
typedef struct Dealer Dealer;

void setInit(Dealer* dealer, Gamer* player1, Gamer* player2);	// 각 참가자의 game에 필요한 변수를 초기화하는 함수
void clearData(Dealer* dealer, Gamer* player1, Gamer* player2);	// 각 참가자의 메모리를 0으로 초기화하는 함수
char int_to_cardNumber(int number);	 // 입력된 숫자를 가지고 카드 넘버로 바꾸는 함수
char cardNumber_to_int(char number); // 입력된 카드 넘버를 블랙잭 숫자로 바꾸는 함수
void filldeck(Deck* deck); // 덱 구성
void betting(Gamer* player);	// 배팅금액 입력 받기
void calCardSum(Gamer* gamer); // 카드 합 계산
void input_player(Gamer* gamer);	// gamer의 이름과 돈을 입력 받는 함수
int choiceAction(Gamer* player);	// 카드를 가져올지 묻는 함수
void remember_dealer(Dealer* dealer, Card card);	// 딜러가 카드를 기억하는 함수
int expect_dealer(Dealer* dealer);		// 딜러가 예측을 하는 함수
int result_sum(Gamer* gamer);		// 게이머가 가진 카드 합을 반환하는 함수

#endif // !SOURCE
