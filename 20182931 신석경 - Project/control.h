#ifndef CONTROL
#define CONTROL

int gameStartOption();	// 게임 시작을 묻는 함수
int gameContinueOption();	// 게임을 계속할지 묻는 함수
void shuffle(Deck* deck);	// 덱 섞기
void mainControl(Deck* deck, Dealer* dealer, Gamer* player1, Gamer* player2);	// 게임 진행 컨트롤 함수
void compare(Dealer* dealer, Gamer* player1, Gamer* player2);		// 한 게임이 끝나고 카드 합 비교하여 승자를 결정하는 함수
#endif // !CONTROL
