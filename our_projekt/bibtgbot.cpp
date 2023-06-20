
#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <stdio.h>
#include <tgbot/tgbot.h>
#include <vector>
#include <ctime>
#include <curl/curl.h>
#include "json.hpp"

//using namespace std;
//using namespace TgBot;

std::vector<std::string>bot_commands = {"start", "time", "currency_type", "info", "converte", "list_of_currency", "convertetion"};

std::string get_time(){
    time_t now = time(NULL);
    tm* ptr = localtime(&now);
    char buf[32];
    strftime(buf, 32, "%c",ptr);
    return buf;
}

static size_t Writer(char *buffer,size_t size, size_t nmemb, std::string *html){
    int result = 0;

    if(buffer  != NULL){
        html->append(buffer, size*nmemb);
        result = size*nmemb;
    }
    return result;
}

std::string get_request(std::string link){
    CURL *curl;
    std::string data;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Writer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return data;
}
/*
float get_number(char num, int fnum){
    auto js_obj = nlohmann::json::parse(get_request("https://www.cbr-xml-daily.ru/daily_json.js"));
    if(num=='a'){
        printf("121212112121212121");
        return js_obj["Valute"]["USD"]["Value"].get<float>()*fnum;
    }
    if(num=='b'){
        return js_obj["Valute"]["EUR"]["Value"].get<float>()*fnum;
    }
    if(num=='c'){
        return js_obj["Valute"]["GBP"]["Value"].get<float>()*fnum;
    }
    if(num=='d'){
        return js_obj["Valute"]["BYN"]["Value"].get<float>()*fnum;
    }
    if(num=='e'){
        return js_obj["Valute"]["UAH"]["Value"].get<float>()*fnum;
    }
    if(num=='f'){
        return js_obj["Valute"]["CNY"]["Value"].get<float>()*fnum;
    }
    if(num=='g'){
        return js_obj["Valute"]["KZT"]["Value"].get<float>()*fnum;
    }
    if(num=='h'){
        return js_obj["Valute"]["UZS"]["Value"].get<float>()*fnum;
    }
    if(num=='i'){
        return js_obj["Valute"]["CAD"]["Value"].get<float>()*fnum;
    }
    if(num=='j'){
        return  js_obj["Valute"]["JPY"]["Value"].get<float>()*fnum;
    }
    else{
        return 0;
    }

    return -1;
}
*/
float get_value(char what){
    auto js_obj = nlohmann::json::parse(get_request("https://www.cbr-xml-daily.ru/daily_json.js"));
    if(what=='a'){
        return js_obj["Valute"]["USD"]["Value"].get<float>();
    }
    if(what=='b'){
        return js_obj["Valute"]["EUR"]["Value"].get<float>();
    }
    if(what=='c'){
        return js_obj["Valute"]["GBP"]["Value"].get<float>();
    }
    if(what=='d'){
        return js_obj["Valute"]["BYN"]["Value"].get<float>();
    }
    if(what=='e'){
        return js_obj["Valute"]["UAH"]["Value"].get<float>();
    }
    if(what=='f'){
        return js_obj["Valute"]["CNY"]["Value"].get<float>();
    }
    if(what=='g'){
        return js_obj["Valute"]["KZT"]["Value"].get<float>();
    }
    if(what=='h'){
        return js_obj["Valute"]["UZS"]["Value"].get<float>();
    }
    if(what=='i'){
        return js_obj["Valute"]["CAD"]["Value"].get<float>();
    }
    if(what=='j'){
        return  js_obj["Valute"]["JPY"]["Value"].get<float>();
    }
    else{
        return 0;
    }

    return -1;
}

int main() {
    system("chcp 1251>nul");
    TgBot::Bot bot("5966035371:AAE-leTtpx8uZULfebFqaM1KZHi6H0HlsCk");
    /*
    bot.getEvents().onCommand("time", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Время по Москве: " + get_time());
    });
    */

    TgBot::InlineKeyboardMarkup::Ptr starting(new TgBot::InlineKeyboardMarkup);
    std::vector<TgBot::InlineKeyboardButton::Ptr> b1;
    std::vector<TgBot::InlineKeyboardButton::Ptr> b2;
    std::vector<TgBot::InlineKeyboardButton::Ptr> b3;
    TgBot::InlineKeyboardButton::Ptr info(new TgBot::InlineKeyboardButton), list_of_curr(new TgBot::InlineKeyboardButton), currency_type(new TgBot::InlineKeyboardButton), time_MSK(new TgBot::InlineKeyboardButton), converte_f(new TgBot::InlineKeyboardButton);
    info->text = "Info";
    converte_f->text = "Конвертировать валюту";
    currency_type->text = "Выбор валюты";
    time_MSK->text = "Время по Москве";
    list_of_curr->text = "Список валют";
    info->callbackData = "info";
    converte_f->callbackData = "converte";
    currency_type->callbackData = "currency_type";
    time_MSK->callbackData = "time";
    list_of_curr->callbackData = "list_of_currency";
    b1.push_back(info);
    b1.push_back(currency_type);
    b2.push_back(time_MSK);
    b2.push_back(converte_f);
    b3.push_back(list_of_curr);
    starting->inlineKeyboard.push_back(b1);
    starting->inlineKeyboard.push_back(b2);
    starting->inlineKeyboard.push_back(b3);

    TgBot::InlineKeyboardMarkup::Ptr convkey(new TgBot::InlineKeyboardMarkup);
    std::vector<TgBot::InlineKeyboardButton::Ptr> but10;
    std::vector<TgBot::InlineKeyboardButton::Ptr> but20;
    std::vector<TgBot::InlineKeyboardButton::Ptr> but30;
    std::vector<TgBot::InlineKeyboardButton::Ptr> but40;
    std::vector<TgBot::InlineKeyboardButton::Ptr> but50;
    std::vector<TgBot::InlineKeyboardButton::Ptr> but60;
    TgBot::InlineKeyboardButton::Ptr usd_butn(new TgBot::InlineKeyboardButton), conve_butn(new TgBot::InlineKeyboardButton), eur_butn(new TgBot::InlineKeyboardButton), gbp_butn(new TgBot::InlineKeyboardButton), byn_butn(new TgBot::InlineKeyboardButton), uah_butn(new TgBot::InlineKeyboardButton), cny_butn(new TgBot::InlineKeyboardButton), kzt_butn(new TgBot::InlineKeyboardButton), uzt_butn(new TgBot::InlineKeyboardButton),cad_butn(new TgBot::InlineKeyboardButton), jpy_butn(new TgBot::InlineKeyboardButton);

    usd_butn->text = "USD";
    usd_butn->callbackData = "USD";
    eur_butn->text = "EUR";
    eur_butn->callbackData = "EUR";
    gbp_butn->text = "GBP";
    gbp_butn->callbackData = "GBP";
    byn_butn->text = "BYN";
    byn_butn->callbackData = "BYN";
    uah_butn->text = "UAH";
    uah_butn->callbackData = "UAH";
    cny_butn->text = "CNY";
    cny_butn->callbackData = "CNY";
    kzt_butn->text = "KZT";
    kzt_butn->callbackData = "KZT";
    uzt_butn->text = "UZS";
    uzt_butn->callbackData = "UZS";
    cad_butn->text = "CAD";
    cad_butn->callbackData = "CAD";
    jpy_butn->text = "JPY";
    jpy_butn->callbackData = "JPY";
    conve_butn->text = "Конвертировать";
    conve_butn->callbackData = "convertetion";

    but10.push_back(usd_butn);
    but10.push_back(eur_butn);
    but20.push_back(gbp_butn);
    but20.push_back(byn_butn);
    but30.push_back(uah_butn);
    but30.push_back(cny_butn);
    but40.push_back(kzt_butn);
    but40.push_back(uzt_butn);
    but50.push_back(cad_butn);
    but50.push_back(jpy_butn);
    but60.push_back(conve_butn);    
    convkey->inlineKeyboard.push_back(but10);
    convkey->inlineKeyboard.push_back(but20);
    convkey->inlineKeyboard.push_back(but30);
    convkey->inlineKeyboard.push_back(but40);
    convkey->inlineKeyboard.push_back(but50);
    convkey->inlineKeyboard.push_back(but60);

    //-----------------------------------------------------
    TgBot::InlineKeyboardMarkup::Ptr keyboard(new TgBot::InlineKeyboardMarkup);
    std::vector<TgBot::InlineKeyboardButton::Ptr> but1;
    std::vector<TgBot::InlineKeyboardButton::Ptr> but2;
    std::vector<TgBot::InlineKeyboardButton::Ptr> but3;
    std::vector<TgBot::InlineKeyboardButton::Ptr> but4;
    std::vector<TgBot::InlineKeyboardButton::Ptr> but5;
    TgBot::InlineKeyboardButton::Ptr usd_btn(new TgBot::InlineKeyboardButton), eur_btn(new TgBot::InlineKeyboardButton), gbp_btn(new TgBot::InlineKeyboardButton), byn_btn(new TgBot::InlineKeyboardButton), uah_btn(new TgBot::InlineKeyboardButton), cny_btn(new TgBot::InlineKeyboardButton), kzt_btn(new TgBot::InlineKeyboardButton), uzt_btn(new TgBot::InlineKeyboardButton),cad_btn(new TgBot::InlineKeyboardButton), jpy_btn(new TgBot::InlineKeyboardButton);

    usd_btn->text = "USD";
    usd_btn->callbackData = "USD";
    eur_btn->text = "EUR";
    eur_btn->callbackData = "EUR";
    gbp_btn->text = "GBP";
    gbp_btn->callbackData = "GBP";
    byn_btn->text = "BYN";
    byn_btn->callbackData = "BYN";
    uah_btn->text = "UAH";
    uah_btn->callbackData = "UAH";
    cny_btn->text = "CNY";
    cny_btn->callbackData = "CNY";
    kzt_btn->text = "KZT";
    kzt_btn->callbackData = "KZT";
    uzt_btn->text = "UZS";
    uzt_btn->callbackData = "UZS";
    cad_btn->text = "CAD";
    cad_btn->callbackData = "CAD";
    jpy_btn->text = "JPY";
    jpy_btn->callbackData = "JPY";

    but1.push_back(usd_btn);
    but1.push_back(eur_btn);
    but2.push_back(gbp_btn);
    but2.push_back(byn_btn);
    but3.push_back(uah_btn);
    but3.push_back(cny_btn);
    but4.push_back(kzt_btn);
    but4.push_back(uzt_btn);
    but5.push_back(cad_btn);
    but5.push_back(jpy_btn);    
    keyboard->inlineKeyboard.push_back(but1);
    keyboard->inlineKeyboard.push_back(but2);
    keyboard->inlineKeyboard.push_back(but3);
    keyboard->inlineKeyboard.push_back(but4);
    keyboard->inlineKeyboard.push_back(but5);
    //-----------------------------------------------------
    bot.getEvents().onCommand("start", [&bot, &starting](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Здравствуйте, " + message->chat->firstName + ", вас приветствует Telegram Bot, который позволяет вам узнать актуальный курс на сегодняшний день.\nВот, что я умею", false , 0 , starting);
    });
    //информация о боте
    bot.getEvents().onCommand("info", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "\tДанный бот создан студентами НИУ ВШЭ с факультета информационной безопасности в рамках дисциплины алгоритмизация и программирования.\n\t Данный бот может выводить актуальный курс валют, конвертировать их и строить графики курса.\n\t Вот полный список команд доступных вам:\n /start - команда для запуска бота\n /info - полная информация о боте\n /time - время по Москве\n /currency_type - выбор интересующей вас валюты\n /converte - конвертирует ллюбую валюту");
    });
    bot.getEvents().onCallbackQuery([&bot, &keyboard](TgBot::CallbackQuery::Ptr informationf) {
        if(informationf->data == "info"){
            bot.getApi().sendMessage(informationf->message->chat->id, "\tДанный бот создан студентами НИУ ВШЭ с факультета информационной безопасности в рамках дисциплины алгоритмизация и программирования.\n\t Данный бот может выводить актуальный курс валют, конвертировать их и строить графики курса.\n\t Вот полный список команд доступных вам:\n /start - команда для запуска бота\n /info - полная информация о боте\n /time - время по Москве\n /currency_type - выбор интересующей вас валюты\n /converte - конвертирует ллюбую валюту");
        }
    });
    //конец информации
/*
    //конверт
    bot.getEvents().onCallbackQuery([&bot, &convkey](TgBot::CallbackQuery::Ptr converte){
        if(converte->data == "converte"){
            bot.getApi().sendMessage(converte->message->chat->id, "Вв");
            bot.getApi().sendMessage(converte->message->chat->id, "Введите валюту и сумму, которую вы хотите конвертировать, в формате a 100");
                
    
    float a;
    bot.getEvents().onCommand("convertetion", [&bot, &convkey, a](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Введите сумму, которую хотите конвертировать: ");
        std::string text = message->text;
        std::istringstream iss(text);
        std::string command;
        iss >> command;
        iss >> a;
        bot.getEvents().onCallbackQuery([&bot, &convkey](TgBot::CallbackQuery::Ptr query) {
        
            if(query->data == "USD"){
                bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('A')*a));
            }
            if(query->data == "EUR"){
                bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('B')));
            }
            if(query->data == "GBP"){
                bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('C')));
            }
            if(query->data == "BYN"){
                bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('D')));
            }
            if(query->data == "UAH"){
                bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('E')));
            }
            if(query->data == "CNY"){
                bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('F')));
            }
            if(query->data == "KZT"){
                bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('G')));
            }
            if(query->data == "UZS"){
                bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('h')));
            }
            if(query->data == "CAD"){
                bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('I')));
            }
            if(query->data == "JPY"){
                bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('J')));
            }
            else{
                bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
                bot.getApi().sendMessage(message->chat->id, "К ссожалению я не могу расспознать вашу команду");
                });
            }
            return -1;
        });
        if (!iss.fail()) {
            int sum = a + b;
            bot.getApi().sendMessage(message->chat->id, "Сумма чисел: " + std::to_string(sum));
        } else {
            bot.getApi().sendMessage(message->chat->id, "Некорректный ввод. Введите два числа через пробел.");
        }
    });
            bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
                printf ("aaaaaaaaa");
            std::string text = message->text;
            auto pos = text.find(" ");
            if (pos != std::string::npos){
                std::string s1 = text.substr(0,pos);
                std::string s2 = text.substr(pos+1);
                std::istringstream iss(s2);
                int a;
                iss >> a;
                char c[256];
                strcpy(c,s1.c_str());
                char lok;
                0[c]=lok;
                bot.getApi().sendMessage(message->chat->id, std::to_string(get_number("a", a)));
                };
            });
        }
    }); 
    */
    //bot.getApi().deleteWebhook();
    //конец конвертра

    //вывод времени
    bot.getEvents().onCommand("time", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Время по Москве: " + get_time()); 
    });
    bot.getEvents().onCallbackQuery([&bot, &keyboard](TgBot::CallbackQuery::Ptr timet) {
        if(timet->data == "time"){
            bot.getApi().sendMessage(timet->message->chat->id, "Время по Москве: " + get_time());
        }
    });
    //конец вывода времени

    bot.getEvents().onCommand("list_of_currency", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Список валют доступных в боте:\nUSD - доллар США\nEUR - евро\nGBP - фунт стерлинга\nUAH - гривна\nBYN - белорусский рубль\nCNY - юань\nKZT - тенге\nUZT - суммы\nCAD - канадский доллар\nJPY - иены"); 
    });
    bot.getEvents().onCallbackQuery([&bot, &keyboard](TgBot::CallbackQuery::Ptr loc) {
        if(loc->data == "list_of_currency"){
            bot.getApi().sendMessage(loc->message->chat->id, "Список валют доступных в боте:\nUSD - доллар США\nEUR - евро\nGBP - фунт стерлинга\nUAH - гривна\nBYN - белорусский рубль\nCNY - юань\nKZT - тенге\nUZT - суммы\nCAD - канадский доллар\nJPY - иены");
        }
    });

    //выбор и вывод валюты
    bot.getEvents().onCommand("currency_type", [&bot, &keyboard](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Выберите валюту, курс которой хотите узнать ", false , 0 , keyboard);
    });
    bot.getEvents().onCallbackQuery([&bot, &keyboard](TgBot::CallbackQuery::Ptr curr_type){
        if(curr_type->data == "currency_type"){
            bot.getApi().sendMessage(curr_type->message->chat->id, "Выберите валюту, курс которой хотите узнать ", false , 0 , keyboard );
        }
    });
    bot.getEvents().onCallbackQuery([&bot, &keyboard](TgBot::CallbackQuery::Ptr query) {
        
        if(query->data == "USD"){
            bot.getApi().sendMessage(query->message->chat->id, "За один USD ЦБ РФ готов вам дать:");
            bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('a')));
            bot.getApi().sendMessage(query->message->chat->id, "рублей.");
        }
        if(query->data == "EUR"){
            bot.getApi().sendMessage(query->message->chat->id, "За один EUR ЦБ РФ готов вам дать:");
            bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('b')));
            bot.getApi().sendMessage(query->message->chat->id, "рублей.");
        }
        if(query->data == "GBP"){
            bot.getApi().sendMessage(query->message->chat->id, "За один GBP ЦБ РФ готов вам дать:");
            bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('c')));
            bot.getApi().sendMessage(query->message->chat->id, "рублей.");
        }
        if(query->data == "BYN"){
            bot.getApi().sendMessage(query->message->chat->id, "За один BYN ЦБ РФ готов вам дать:");
            bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('d')));
            bot.getApi().sendMessage(query->message->chat->id, "рублей.");
        }
        if(query->data == "UAH"){
            bot.getApi().sendMessage(query->message->chat->id, "За один UAH ЦБ РФ готов вам дать:");
            bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('e')));
            bot.getApi().sendMessage(query->message->chat->id, "рублей.");
        }
        if(query->data == "CNY"){
            bot.getApi().sendMessage(query->message->chat->id, "За один CNY ЦБ РФ готов вам дать:");
            bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('f')));
            bot.getApi().sendMessage(query->message->chat->id, "рублей.");
        }
        if(query->data == "KZT"){
            bot.getApi().sendMessage(query->message->chat->id, "За один KZT ЦБ РФ готов вам дать:");
            bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('g')));
            bot.getApi().sendMessage(query->message->chat->id, "рублей.");
        }
        if(query->data == "UZS"){
            bot.getApi().sendMessage(query->message->chat->id, "За один UZS ЦБ РФ готов вам дать:");
            bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('h')));
            bot.getApi().sendMessage(query->message->chat->id, "рублей.");
        }
        if(query->data == "CAD"){
            bot.getApi().sendMessage(query->message->chat->id, "За один CAD ЦБ РФ готов вам дать:");
            bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('i')));
            bot.getApi().sendMessage(query->message->chat->id, "рублей.");
        }
        if(query->data == "JPY"){
            bot.getApi().sendMessage(query->message->chat->id, "За один JPY ЦБ РФ готов вам дать:");
            bot.getApi().sendMessage(query->message->chat->id, std::to_string(get_value('j')));
            bot.getApi().sendMessage(query->message->chat->id, "рублей.");
        }
        else{
            bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
            bot.getApi().sendMessage(message->chat->id, "К ссожалению я не могу расспознать вашу команду");
            });
        }
        return -1;
    });
    bot.getApi().deleteWebhook();
    //конец валют 
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        //printf("User wrote %s\n", message->text.c_str());
        for(const auto& command : bot_commands){
            if("/"+command==message->text){
                return;
            }
        }
        bot.getApi().sendMessage(message->chat->id, "Извините, я не понял вашу команду: " + message->text);
    });


    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
};
//         g++ bibtgbot.cpp -o bibtgbot --std=c++14 -I/usr/local/incluude -lTgBot -lboost_system -lssl -lcrypto -lpthread -lcurl
//         ./bibtgbot
