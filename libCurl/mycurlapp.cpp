#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(void) // remember, use -lcurl when compiling and compile on a linux platform like wsl
{
    CURL *hnd = curl_easy_init();

    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, stdout);
    curl_easy_setopt(hnd, CURLOPT_URL, "https://trading-api.kalshi.com/trade-api/v2/exchange/status");

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "accept: application/json");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

    CURLcode ret = curl_easy_perform(hnd);

    return EXIT_SUCCESS;
}