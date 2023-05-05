#include <stdio.h>
#include <string.h>

int main() {
    char octal[333335]; // 8진수 최대 길이는 333,334자리이므로 333,335로 설정
    char binary[1000001] = ""; // 2진수 문자열을 저장할 배열
    int i, j, k, len, b_len = 0;

    scanf("%s", octal);
    len = strlen(octal);

    // 8진수 한 자리씩 2진수로 변환하여 binary 배열에 추가
    for (i = 0; i < len; i++) {
        int oct = octal[i] - '0';
        for (j = 0, k = 4; j < 3; j++, k /= 2) {
            binary[b_len++] = (oct / k) % 2 + '0';
        }
    }

    // 2진수 문자열 출력
    if (b_len == 0) {
        printf("0");
    } else {
        // 앞쪽 0 제거
        while (binary[b_len - 1] == '0') {
            b_len--;
        }
        for (i = b_len - 1; i >= 0; i--) {
            printf("%c", binary[i]);
        }
    }

    return 0;
}
