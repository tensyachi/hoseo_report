#include <stdio.h>
#define MAX_ID 100
#define MAX_AMT 100

int idin();
int varin();

void main() {
	int amount[MAX_ID] = { 0 };
	int item[MAX_ID][MAX_AMT] = { 0 };
	int mod, id, cnt, io;

	do {
		printf("기능을 선택해 주세요.\n");
		printf("1) 상품 재고를 입력한다.\n");
		printf("2) 상품 재고를 확인한다.\n");
		printf("3) 프로그램을 종료한다.\n>>");
		scanf("%d", &mod);

		if (mod == 1) {
			id = idin();
			cnt = varin();
			amount[id] = cnt;

			printf("상품별 입고 수량을 입력해 주세요. >>");
			for (int i = 0; i < cnt; i++) {
				scanf("%d", &io);

				if (io < 0) {
					printf("재고는 0 이상이어야 합니다.\n");
					i--;
				}
				else {
					item[id][i] += io;
				}
			}

			printf("상품별 판매 수량을 입력해 주세요. >>");
			for (int i = 0; i < cnt; i++) {
				scanf("%d", &io);

				if (io > item[id][i]) {
					printf("판매 수량은 재고보다 적어야 합니다.\n");
					i--;
				}
				else if (io < 0) {
					printf("판매 수량은 0 이상이어야 합니다.\n");
					i--;
				}
				else {
					item[id][i] -= io;
				}
			}
			printf("재고가 저장되었습니다.\n");
			printf("\n--------------------------------------------------------\n\n");
		}
		else if (mod == 2) {
			id = idin();
			cnt = amount[id];

			printf("상품 종류 : %d종\n", cnt);
			for (int i = 0; i < cnt; i++) {
				printf("상품%d 수량 : %d개\n", i + 1, item[id][i]);
			}
			printf("\n--------------------------------------------------------\n\n");
		}
		else if (mod == 3) {
			printf("프로그램이 종료됩니다.");
		}
		else {
			printf("잘못된 입력입니다.\n");
			printf("\n--------------------------------------------------------\n\n");
		}
	} while (mod != 3);
}

int idin() {
	int fid;

	do {
		printf("\n--------------------------------------------------------\n\n");
		printf("상품의 ID를 입력해 주세요.(1~%d) >>", MAX_ID);
		scanf("%d", &fid);

		if (1 > fid || fid > MAX_ID) {
			printf("ID는 1에서 %d 사이여야 합니다.\n", MAX_ID);
			continue;
		}
	} while (1 > fid || fid > MAX_ID);

	return fid - 1;
}

int varin() {
	int fcnt;

	do {
		printf("상품 종류의 수를 입력해 주세요.(1~%d) >>", MAX_AMT);
		scanf("%d", &fcnt);

		if (1 > fcnt || fcnt > MAX_AMT) {
			printf("종류는 1에서 %d 사이여야 합니다.\n", MAX_AMT);
			printf("\n--------------------------------------------------------\n\n");
			continue;
		}
	} while (1 > fcnt || fcnt > MAX_AMT);

	return fcnt;
}