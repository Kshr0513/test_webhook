#include <string>
#include <json.hpp>
#include <ctime>
#include "funcJson.h"
using namespace std;
using json = nlohmann::json;

namespace funcJson{
    string makeStrJsonFormat(string title) {
        //現在日時の取得
        time_t now = time(nullptr);
        char* datetime = ctime(&now);
        //jsonデータの作成
        json j;
        j["embeds"] = json::array({
            {
                {"title", title},
                {"description", string(datetime)},
                {"color", 5814783},
                {"author", {{"name", "Post request from C++"}}},
                {"fields", json::array({
                    {
                        {"name", "フィールド1"},
                        {"value", "値1"},
                        {"inline", false}
                    }
                })}
            }
        });
        string body = j.dump();
        return body;
    }
}