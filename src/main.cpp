#include <iostream>
#include <string>
#include <curl/curl.h>
//#include "funcJson.h"
#include "funcWebhook.h"
using namespace std;

int main() {
    cout << "プログラムの開始" << endl;
    funcWebhook::sendMessage();
    cout << "プログラムの終了" << endl;
    return 0;
}
/*
Siv3DでDiscord Webhookのクライアントを作ってみた話
https://qiita.com/hota1024/items/bd9e76379154b1663612
libcurl公式チュートリアルを和訳してまとめていく
https://qiita.com/suneo3476/items/a00113de2d005fa50440
Makefileの書き方 (初心者向け)
https://qiita.com/yagiyuki/items/ff343d381d9477e89f3b
C++のjsonライブラリ決定版 nlohmann-json
https://qiita.com/yohm/items/0f389ba5c5de4e2df9cf
#31 [C/C++] 日付と時間の取得
https://note.com/brain_up0505/n/n3da8b5a584a9
discord webhook リファレンス
https://discord.com/developers/docs/resources/webhook
全人類、いますぐ Discord Webhook を使いこなそう
https://zenn.dev/discorders/articles/discord-webhook-guide
*/