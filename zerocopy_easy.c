#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>

int main()
{
    setbuf(stdout, 0);

    CURL *easyzc = curl_easy_init();
    CURLcode result;
    int globalInit;
    char *errbuf = malloc(CURL_ERROR_SIZE);

    char *filename = "test_output.html";
    char *url = "http://pi.math.cornell.edu/~mec/2003-2004/cryptography/subs/frequencies.html";

    globalInit = curl_global_init(CURL_GLOBAL_ALL);

    if (globalInit)
    {
        printf("curl_global_init failed \n");
        return 1;
    }

    curl_easy_setopt(easyzc, CURLOPT_URL, url);
    curl_easy_setopt(easyzc, CURLOPT_WRITEDATA, (void *) filename);
    curl_easy_setopt(easyzc, CURLOPT_ERRORBUFFER, errbuf);
    curl_easy_setopt(easyzc, CURLOPT_VERBOSE, 1);
    
    result = curl_easy_perform_zc(easyzc);

    if (result == CURLE_OK)
    {
        printf("curl_easy_perform_zc successful\n");
    }
    else
    {
        printf("curl_easy_perform_zc returned other than CURLE_OK\n");
        printf("%s \n", errbuf);
    }

    free(errbuf);
    curl_global_cleanup();

    return 0;
}
