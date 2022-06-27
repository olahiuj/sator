#include <stdio.h>

static const char fmt[] = "notify-send \"%s\"";

int main(int argc, char *argv[]) {
  FILE *pf = popen("xclip -o", "r");
  if (pf == NULL) {
    perror("popen");
    exit(1);
  }

  static char word[NR_BUF];
  fgets(word, sizeof(word) - 1, pf);
  pclose(pf);

  static char notify[NR_BUF];
  snprintf(notify, sizeof(fmt) - 1, fmt, word);
  system(notify);

  return 0;
}
