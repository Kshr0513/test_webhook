#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json.hpp>
#include <ctime>
using namespace std;
using json = nlohmann::json;

int main() {
    cout << "Hello, World!" << endl;
    //通信設定・接続状態・結果などをまとめて持つ「操作単位」
    CURL *hnd;

    //通信実行時の戻り値を格納する変数
    CURLcode res;

    //ハンドルの初期化
    hnd = curl_easy_init();
    if(hnd){
        //POSTリクエストの設定
        curl_easy_setopt(hnd, CURLOPT_POST, 1);
        //Url(discordのWebhookURL)の設定
        curl_easy_setopt(hnd, CURLOPT_URL, "URL");
        
        //jsonデータの作成
        json j;
        j["content"] = string("Hello! From C++ program To Discord channel ");//+ to_string(time(NULL));
        //POSTデータの設定
        curl_easy_setopt(hnd, CURLOPT_POSTFIELDS,"payload_json={\"content\": \"Hello! From C++ program To Discord channel\"}");
        //curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, j.dump().c_str());
        //データサイズの設定
        curl_easy_setopt(hnd, CURLOPT_POSTFIELDSIZE, -1L);
        //通信の実行
        res = curl_easy_perform(hnd);
        if(res != CURLE_OK){
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }
        //ハンドルのクリーンアップ
        curl_easy_cleanup(hnd);
    }
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
*/