#include <string>
#include <json.hpp>
#include "funcJson.h"
using namespace std;
using json = nlohmann::json;

namespace funcJson{
    string makeStrJsonFormat(string title) {
        //jsonデータの作成
        json j;
        j["embeds"] = json::array({
            {
                {"title", title},
                {"description", "説明文"},
                {"color", 5814783},
                {"fields", json::array({
                    {
                        {"name", "フィールド1"},
                        {"value", "値1"},
                        {"inline", true}
                    },
                    {
                        {"name", "フィールド2"},
                        {"value", "値2"},
                        {"inline", true}
                    }
                })}
            }
        });
        string body = j.dump();
        return body;
    }
}