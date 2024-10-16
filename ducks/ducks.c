#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ITERATES 104857600
#define NUM_THREADS 16

struct Point {
  // [0, 1]
  double r;
  // [0, 2 * pi]
  double theta;
};

/* generate a random floating point number from min to max */
double randfrom(double min, double max) {
  double range = (max - min);
  double div = RAND_MAX / range;
  return min + (rand() / div);
}

struct Point generateAPointInCircle() {
  const double radious = 1;

  const double r = sqrt(randfrom(0, radious));
  const double theta = randfrom(0, 2 * M_PI);

  return (struct Point){.r = r, .theta = theta};
}

bool numInRange(double num, double low, double high) {
  return (low <= num) && (num <= high);
}

bool testIfDivided() {
  // generate
  struct Point points[4];
  for (int i = 0; i < 4; i++) {
    points[i] = generateAPointInCircle();
    // printf("%f %f \n", points[i].r, points[i].theta);
  }

  // for each point, find if can be Divided
  bool found = false;
  for (int i = 0; found == false && i < 4; i++) {
    // corresponding Point (+ pi)
    struct Point aliasPoint = (struct Point){
        .r = points[i].r, .theta = fmod(points[i].theta + M_PI, 2 * M_PI)};

    bool andBit = 1, orBit = 0;
    if (aliasPoint.theta > points[i].theta) {
      for (int j = (i + 1) % 4; j != i; j = (j + 1) % 4) {
        const bool isInRange =
            numInRange(points[j].theta, points[i].theta, aliasPoint.theta);
        // Check if 0 Included
        andBit = andBit && isInRange;
        // Check if 1 Included
        orBit = orBit || isInRange;
      }
      // Only 0, 0, 0 or 1, 1, 1 is accepted
      // 0, 0, 0 don't have 1 , 1, 1, 1 don't have 0
      found = (andBit == 0 && orBit == 0) || (andBit == 1 && orBit == 1);
      continue;
    }

    // aliasPoint.theta < points[i].theta
    for (int j = (i + 1) % 4; j != i; j = (j + 1) % 4) {
      const bool isInRange =
          numInRange(points[j].theta, aliasPoint.theta, points[i].theta);
      // Check if 0 Included
      andBit = andBit && isInRange;
      // Check if 1 Included
      orBit = orBit || isInRange;
    }
    // Only 0, 0, 0 or 1, 1, 1 is accepted
    // 0, 0, 0 don't have 1 , 1, 1, 1 don't have 0
    found = (andBit == 0 && orBit == 0) || (andBit == 1 && orBit == 1);
  }
  // printf("%s\n", found ? "Found" : "Not found");
  return found;
}

unsigned long canBeDividedCounter = 0;
unsigned long cannotBeDividedCounter = 0;
// Protect two counters
pthread_mutex_t counterMutex;

pthread_t threads[NUM_THREADS];

void *simulate(void *args) {
  // ignore arguments
  (void)args;

  const unsigned long numInterations = TOTAL_ITERATES / NUM_THREADS;

  unsigned long partlyCanBeDividedCounter = 0, partlyCannotBeDividedCounter = 0;
  for (unsigned long i = 0; i < numInterations; i++) {
    if (testIfDivided()) {
      partlyCanBeDividedCounter++;
      continue;
    }
    // cannot be Divided
    partlyCannotBeDividedCounter++;
  }

  pthread_mutex_lock(&counterMutex);
  canBeDividedCounter += partlyCanBeDividedCounter;
  cannotBeDividedCounter += partlyCannotBeDividedCounter;
  pthread_mutex_unlock(&counterMutex);

  return NULL;
}

int main(void) {
  // time as random number generator seed
  srand(time(NULL));

  pthread_mutex_init(&counterMutex, NULL);
  // make threads running
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, simulate, NULL);
  }
  // wait threads finished
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  pthread_mutex_destroy(&counterMutex);

  const double probability =
      (double)canBeDividedCounter /
      (double)(canBeDividedCounter + cannotBeDividedCounter);

  printf("Frequency=%.10f canBeDividedCounter=%ld cannotBeDividedCounter=%ld\n", probability, canBeDividedCounter,
         cannotBeDividedCounter);
}
