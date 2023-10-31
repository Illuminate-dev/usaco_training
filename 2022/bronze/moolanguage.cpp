#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
  cin >> T;
  while (T--) {
    int N, C, P;
    vector<string> nouns, tverbs, iverbs, conjs;

    cin >> N >> C >> P;

    for (int i = 0; i < N; i++) {
      string word, type;
      cin >> word >> type;

      if (type == "noun") {
        nouns.push_back(word);
      } else if (type == "transitive-verb") {
        tverbs.push_back(word);
      } else if (type == "intransitive-verb") {
        iverbs.push_back(word);
      } else {
        conjs.push_back(word);
      }
    }

    int ans = 0;

    int t1, t2, combine, tack_end;
    for (int type_1 = 0; type_1 <= iverbs.size(); type_1++) {
      int noun_cnt = nouns.size(), conj_cnt = conjs.size();
      int period = P, comma = C;
      int cur_words = 0;

      // make type_1 of t1 sentences
      cur_words += type_1 * 2;
      noun_cnt -= type_1;
      if (noun_cnt < 0)
        continue;

      int type_2 = min(min((int)tverbs.size(), noun_cnt / 2),
                       min(conj_cnt, period) * 2 + max(0, period - conj_cnt));
      cur_words += 3 * type_2;
      noun_cnt -= 2 * type_2;

      int total = type_1 + type_2;
      int can_combine = min(total / 2, conj_cnt);
      cur_words += can_combine;
      period -= total - can_combine;
      if (period < 0)
        continue;

      int tack = 0;
      if (type_2 > 0) {
        tack = min(noun_cnt, comma);
        cur_words += tack;
      }
      if (cur_words > ans) {
        ans = cur_words;
        t1 = type_1;
        t2 = type_2;
        combine = can_combine;
        tack_end = tack;
      }
    }

    cout << ans << endl;

    if (ans == 0) {
      cout << endl;
      continue;
    }

    vector<vector<string>> sentences;
    for (int i = 0; i < t1; i++) {
      sentences.push_back({nouns.back(), iverbs.back()});
      nouns.pop_back();
      iverbs.pop_back();
    }

    for (int i = 0; i < t2; i++) {
      sentences.push_back({nouns.back(), tverbs.back()});
      nouns.pop_back();
      tverbs.pop_back();
      sentences.back().push_back(nouns.back());
      nouns.pop_back();
    }

    string output;
    for (int i = 0; i < sentences.size(); i++) {
      for (string j : sentences[i]) {
        output += j + " ";
      }

      if (i % 2 == 0 && combine) {
        combine--;
        output += conjs.back() + " ";
        conjs.pop_back();
      } else {
        output.pop_back();
        output += ". ";
      }
    }
    output.pop_back();
    if (tack_end > 0) {
      output.pop_back();
      for (int i = 0; i < tack_end; i++) {
        output += ", " + nouns.back();
        nouns.pop_back();
      }
      output.push_back('.');
    }
    cout << output << endl;
  }
}
