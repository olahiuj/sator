#include <stdio.h>
#include <stdlib.h>

#define NR_BUF 4096

static const char notify_fmt[] = "notify-send -h int:transient:1 \"%s\"";
static const char trans_fmt[] = "trans --brief :zh \"%s\"";

FILE *Popen(const char *cmd, const char *type) {
  FILE *pf = popen(cmd, type);
  if (pf == NULL) {
    perror("popen");
    exit(1);
  }
  return pf;
}

int main(int argc, char *argv[]) {
  FILE *pf = Popen("xclip -o", "r");
  static char word_en[NR_BUF];
  fgets(word_en, sizeof(word_en) - 1, pf);
  pclose(pf);

  static char trans[NR_BUF * 2];
  snprintf(trans, sizeof(trans) - 1, trans_fmt, word_en);
  pf = Popen(trans, "r"); 
  static char word_zh[NR_BUF];
  fgets(word_zh, sizeof(word_zh) - 1, pf);
  pclose(pf);

  static char notify[NR_BUF * 2];
  snprintf(notify, sizeof(notify) - 1, notify_fmt, word_zh);
  system(notify);

  return 0;
}
