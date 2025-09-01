#include <stdio.h>

int main(void) {
  int seconds = 0;
  int throttle, fuel = 500;
  float height = 250;
  float velocity = -25;

  printf("Lunar decent challenge!\n");
  printf("Set the throttle for each second (0-100).\n");
  printf("Time(s) Height(m) Velocity(m/s) Fuel(kg)\tThrottle?\n");
  do {
    if (fuel > 0) {
      printf("%3d%11.1f%10.1f%13d\t\t", seconds, height, velocity, fuel);
      // Scanf retunerar 0 om den får fel input
      // getchar() == '\n' rensar strömmen till radbyte
      if (scanf("%d", &throttle) == 0) {
        while (getchar() == '\n')
          ;
        continue;
      }
    } else {
      throttle = 0;
      printf("%3d%11.1f%10.1f%13d\t\t0\n", seconds, height, velocity, fuel);
    }

    if (throttle >= 0 && throttle <= 100) {
      if (fuel >= throttle) {
        fuel = fuel - throttle;
      } else if (fuel > 0 && fuel < throttle) {
        printf("Not enough fuel!\n");
        continue;
      }
      height = height + velocity + (0.1 * throttle - 1.5) / 2;
      velocity = velocity + (0.1 * throttle - 1.5);

      seconds++;
    } else {
      printf("Throttle 0-100!\n");
      continue;
    }
  } while (height > 0);

  (velocity > -2)
      ? printf("\nSuccess! You landed at a speed of %.1f m/s\n", velocity)
      : printf("\nFailed! Crash landing at %.1f m/s\n", velocity);
  return 0;
}
