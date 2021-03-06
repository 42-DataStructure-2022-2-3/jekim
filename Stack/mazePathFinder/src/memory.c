#include "../includes/pathFinder.h"

void freeMaplist(Data *data) {
    MapListNode *nptr = data->maplst;
    MapListNode *tmp;
    // 헤더노드 프리를 위해 노드를 1개 더 해제해주어야 함
    int limit = data->mapHeight + 1;
    for (int i = 0; i < limit; i++) {
        tmp = nptr->next;
        if (i != 0) free(nptr->mapline);
        free(nptr);
        nptr = tmp;
    }
};

int freeMapMatrix(int **map) {
    for (int i = 0; *(map + i); i++) {
        free(map[i]);
    }
    free(map);
    return 0;
};

// 동적할당된 data 오브젝트와 내부의 리스트와 그 멤버변수인 mapline, int **매트릭스 모두 프리하는 함수입니다.
int freeData(Data *data) {
    freeMaplist(data);
    freeMapMatrix(data->mapMatrix);
    free(data);
    data = NULL;
    return CLEARY_DONE;
}