#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>

/*I/O*/
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    setbuf(stdout, 0);

    CURL *easyzc = curl_easy_init();
    curl_mime *mime = curl_mime_init(easyzc);
    CURLcode result;
    int globalInit;
    char *errbuf = malloc(CURL_ERROR_SIZE);

    char *filename = "test_send_zc1.txt";
    char *url = "localhost:5000";
    curl_mimepart *uploadfile = curl_mime_addpart(mime);
    curl_mime_name(uploadfile, "file");
    curl_mime_filedata(uploadfile, filename);
    /*curl_mime_data_cb();*/

    globalInit = curl_global_init(CURL_GLOBAL_ALL);

    if (globalInit)
    {
        printf("curl_global_init failed \n");
        return 1;
    }

    curl_easy_setopt(easyzc, CURLOPT_URL, url);
    curl_easy_setopt(easyzc, CURLOPT_MIMEPOST, mime);
    curl_easy_setopt(easyzc, CURLOPT_ERRORBUFFER, errbuf);
    //curl_easy_setopt(easyzc, CURLOPT_VERBOSE, 1);

    result = curl_easy_perform_zc(easyzc);

    if (result == CURLE_OK)
    {
        printf("\ncurl_easy_perform successful\n");
    }
    else
    {
        printf("curl_easy_perform returned other than CURLE_OK\n");
        printf("%s \n", errbuf);
    }

    free(errbuf);
    curl_mime_free(mime);
    curl_easy_cleanup(easyzc);
    curl_global_cleanup();

    return 0;
}
