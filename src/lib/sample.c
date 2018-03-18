#include <stdlib.h>
#include <sample.h>

struct Sample {
  int amount;
};

Sample * sample_create(int amount) {
  Sample *s;

  if (amount < 0) {
    s = NULL;
  } else {
    s = (Sample *) malloc(sizeof(Sample));
    if (s != NULL) {
      s->amount = amount;
    }
  }

  return s;
}

int sample_amount(Sample * s) {
  if (s != NULL) {
    return s->amount;
  } else {
    return -1;
  }
}

int sample_sum(Sample * s, int x) {
  if (s != NULL) {
    s->amount += x;
    return s->amount;
  } else {
    return -1;
  }
}

void sample_free(Sample * s)
{
  free(s);
  return;
}
