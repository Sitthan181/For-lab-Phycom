#include <stdio.h>
#include <stdlib.h> // สำหรับใช้งานฟังก์ชัน abs()

int main() {
    int start, end;
    // s = ระยะทาง t = เวลา
    scanf("%d %d", &start, &end);
    // มี 6 ชั้นแต่มันนับจาก 0 เลยต้องใส่ 0
    int heights[7] = {0, 0, 6, 10, 14, 18, 22};

    double s_total = (double)abs(heights[start] - heights[end]);

    // กดชั้นเดิม
    if (s_total == 0) {
        printf("0.00\n");
        return 0;
    }

    double v = 1.5;
    double a = 0.5;

    // การเร่ง
    double s_accel = (v * v) / (2 * a);
    double t_accel = v / a;

    // ความเร็วคงที่
    double s_cruise = s_total - (2 * s_accel);
    double t_cruise = s_cruise / v;

    // เวลารวม (เวลาเร่ง + เวลาคงที่ + เวลาชะลอ) เวลาเร่ง/ชะลอเท่ากันเลย*2+คงที่
    double t_total = (2 * t_accel) + t_cruise;

    printf("%.2f\n", t_total);

    return 0;
}
