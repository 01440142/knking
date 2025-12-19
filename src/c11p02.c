#include <stdio.h>

#define FLIGHTS 8
#define AM 'a'
#define PM 'p'
#define MERIDIEM 12
#define POST_MERIDIEM 13
#define HOUR_IN_MINUTES 60
#define DAY_IN_MINUTES 1440

void find_closest_flight(int time, int *departure, int *arrival);
void format_time(int time, int *hour, int *minute, char *c);

int main(void) {
  char c;
  int hour, minute, total;
  int departure, arrival;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &minute);
  total = (hour * HOUR_IN_MINUTES + minute);

  find_closest_flight(total, &departure, &arrival);

  format_time(departure, &hour, &minute, &c);
  printf("Closest Departure time is %.2d:%.2d %c.m.", hour, minute, c);

  format_time(arrival, &hour, &minute, &c);
  printf(", arriving at %.2d:%.2d %c.m.\n", hour, minute, c);
  return 0;
}

void find_closest_flight(int time, int *departure, int *arrival) {
  int departures[] = {480, 583, 679, 767, 840, 945, 1140, 1305};
  int arrivals[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
  int i, flight = -1, last_departure;

  for (i = 0; i < FLIGHTS - 1; i++)
    if (time <= departures[i] + (departures[i + 1] - departures[i]) / 2) {
      flight = i;
      break;
    }

  /* check first against last departure */
  last_departure = DAY_IN_MINUTES - departures[FLIGHTS - 1];
  last_departure = time <= (departures[0] - last_departure) / 2;
  last_departure = flight == 0 && last_departure;
  if (last_departure || flight == -1) {
    flight = FLIGHTS - 1;
  }

  *departure = departures[flight];
  *arrival = arrivals[flight];
}

void format_time(int time, int *hour, int *minute, char *c) {
  *c = ((time / HOUR_IN_MINUTES) < MERIDIEM) ? AM : PM;
  *hour = (time / HOUR_IN_MINUTES);
  if (*hour >= POST_MERIDIEM) {
    *hour -= MERIDIEM;
  }
  *minute = time % HOUR_IN_MINUTES;
}
