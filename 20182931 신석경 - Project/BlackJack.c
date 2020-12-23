/*
* BlackJack.c
* 
* ����: ��ü ���� ���α׷��� ����Ǵ� �ڵ�
* 
* include: source.h, cursor.h, control.h, console.h�� �����
* 
* �Է�: �Է��� �� ��⿡�� ���� ó����
* 
* ���: ���� ������ ����ǰ� �ִ� �帧
* 
* ���� �ڵ� ���� ��¥: 2020.11.21
* ����: 1.0
* �ۼ���: �ż���
* 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "source.h"
#include "cursor.h"
#include "control.h"
#include "console.h"
#include <string.h>
#include <stdlib.h>

int main(void) {
	Deck deck = { 0 };			// �� ����ü ����
	Dealer dealer = { {{"Dealer", 100}, 0,0},0 };	// ���� ����
	Gamer* player1 = (Gamer*)calloc(1, sizeof(Gamer));	// �÷��̾�1 ���� �Ҵ�
	Gamer* player2 = (Gamer*)calloc(1, sizeof(Gamer));	// �÷��̾�2 ���� �Ҵ�

	int option;	// ���� �ɼǵ� ���� ����

	filldeck(&deck);	// �� ���� �Լ� ����

	while (1) {
		console_clear();	// �ܼ� Ŭ����
		gameStart();	// ù ȭ�� ���
		option = gameStartOption();	// ���� �ɼ� �ް�
		if (option == 0)	// 0�̸� ����
			break;
		else {	// �ƴϸ�
			console_clear();	// �ܼ� Ŭ����
			input_player(player1);	// �÷��̾� 1 ���� �ް�
			input_player(player2);	// �÷��̾� 2 ���� �ް�
			console_clear();	// �ܼ� Ŭ����
			printf("������ �����մϴ�!!");
			Sleep(1000);
			console_clear();
			showDeck(&deck, OPEN);	// ī�� ��ü�� �����ְ�
			Sleep(1000);
			console_clear();
			showDeck(&deck, CLOSE);	// ī�� �޸����� ��ü�� �����ְ�
			Sleep(800);
			while (1) {
				console_clear();
				shuffle(&deck);	// ī�带 ����
				console_clear();
				gameSet(&dealer, player1, player2);	// ���� ȭ�� ����
				showMoney(player1, player2);	// �� �÷��̾��� �� ������
				playerSet(player1, player2);	// �� �÷��̾��� ������ �ϰ� ���� �ݾ��� ������
				gotoxy(0, 0);
				line_clear();
				mainControl(&deck, &dealer, player1, player2);	// ��ü ���� �帧 ���
				
				option = gameContinueOption();	// ������ �� �� ������ �Է� �޴� �Լ�
				if (option == 0) {
					gotoxy(0, 0);
					printf("������ �׸��մϴ�.");
					Sleep(1000);
					gotoxy(0, 0);
					line_clear();
					break;
				}
				else {
					gotoxy(0, 0);
					printf("������ ����մϴ�.");
					Sleep(1000);
					gotoxy(0, 0);
					line_clear();
					setInit(&dealer, player1, player2);	// ������ ����ϸ� ������ �ʱ�ȭ ���� �ٽ� ���� ����
				}
			}
			clearData(&dealer, player1, player2);	// ���� ������ �� ó������ �ϰ� ������ �� ������ �޸� �ʱ�ȭ ���� �ٽ� ����
		}
	}
	gotoxy(0, 0);
	console_clear();
	printf("������ �����մϴ�!!\n\n");
	return 0;
}