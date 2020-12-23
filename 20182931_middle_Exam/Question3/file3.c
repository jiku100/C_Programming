#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	int pascal[][10] = { 0, };
	int target;
	while (1) {
		printf("�Ľ�Į�� �ﰢ���� ũ�⸦ �Է��Ͻÿ� >> ");
		scanf("%d", &target);
		if (!(target > 0 && target < 11)) {
			printf(" ?? �ﰢ���� ũ��� 10 ������ ���� �����̾�� �մϴ�.\n\n");
			continue;
		}
		
		for (int n = 0; n < target; n++) {	// target�� ������
			for (int r = 0; r <= n; r++) {
				pascal[n][r] = 1; // ���� ù ���Ҵ� 1�� �ʱ�ȭ
				for (int i = 1; i <= n; i++) {
					pascal[n][r] *= i;	// n! ���
				}
				for (int i = 1; i <= r; i++) {
					pascal[n][r] /= i;	// r!���� ������ �� ���
				}
				for (int i = 1; i <= (n - r); i++) {
					pascal[n][r] /= i;	// (n-r)!���� ������ �� ���
				}
			}
		}


		for (int n = 0; n < target; n++) {
			for (int r = 0; r <= n; r++) {
				printf("%d  ", pascal[n][r]);	// �� ���� ���
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}