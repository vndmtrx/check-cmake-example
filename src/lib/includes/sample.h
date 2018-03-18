#ifndef SAMPLE_H
#define SAMPLE_H

typedef struct Sample Sample;

Sample * sample_create(int amount);
int sample_amount(Sample * s);
int sample_sum(Sample * s, int x);
void sample_free(Sample * s);

#endif /* SAMPLE_H */
