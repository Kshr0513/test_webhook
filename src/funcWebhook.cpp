#include "funcWebhook.h"
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <fstream>
#include <json.hpp>
#include "funcJson.h"
using namespace std;
using json = nlohmann::json;

namespace funcWebhook{
    void sendMessage(){
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
            string filename = "pram.json";
            ifstream ifs(filename.c_str());
            string url;
            if(ifs.good()){
                json j;
                ifs >> j;
                url = j["webhookUrl"]["value"];
            }
            curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());
            //ヘッダー情報の設定
            struct curl_slist* headers = nullptr;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

            //POSTデータの設定
            string body = funcJson::makeStrJsonFormat("JSONフォーマットの関数化");
            curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, body.c_str());
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
    }
}
