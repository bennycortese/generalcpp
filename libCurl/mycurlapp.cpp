#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//Am going to Vancouver right now
void curl_call(string toCall)
{
    CURL *hnd = curl_easy_init();

    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, stdout);
    curl_easy_setopt(hnd, CURLOPT_URL, toCall);

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "accept: application/json");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

    CURLcode ret = curl_easy_perform(hnd);

    return EXIT_SUCCESS;
}

int main(void) // remember, use -lcurl when compiling and compile on a linux platform like wsl
{
    curl_call("https://trading-api.kalshi.com/trade-api/v2/exchange/status");
}
