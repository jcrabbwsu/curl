#include <stdlib.h>
#include <stdio.h>
#include "curl/include/curl/curl.h"

/*I/O*/
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    setbuf(stdout, 0);

    int globalInit;
    globalInit = curl_global_init(CURL_GLOBAL_ALL);

    if (globalInit) {
        printf("curl_global_init failed \n");
        return 1;
    }

    CURL *easyzc = curl_easy_init();
    curl_mime *mimezc = curl_mime_init(easyzc);
    CURLcode result;
    char *errbuf = malloc(CURL_ERROR_SIZE);

    const char *filename_zc = "file_77M_abc_zc.txt";
    const char *url = "localhost:5000";
    curl_mimepart *uploadfile_zc = curl_mime_addpart(mimezc);
    curl_mime_name(uploadfile_zc, "file");
    curl_mime_filedata(uploadfile_zc, filename_zc);
    /*curl_mime_data_cb();*/

    curl_easy_setopt(easyzc, CURLOPT_URL, url);
    //curl_easy_setopt(easyzc, CURLOPT_CRLF, 1L);
    curl_easy_setopt(easyzc, CURLOPT_MIMEPOST, mimezc);
    curl_easy_setopt(easyzc, CURLOPT_ERRORBUFFER, errbuf);
    //curl_easy_setopt(easyzc, CURLOPT_VERBOSE, 1);

    result = curl_easy_perform_zc(easyzc);

    if (result == CURLE_OK) {
        printf("curl_easy_perform_zc successful\n");
    } else {
        printf("curl_easy_perform_zc returned other than CURLE_OK\n");
        printf("%s \n", errbuf);
    }

    CURL *easyst = curl_easy_init();
    curl_mime *mimest = curl_mime_init(easyst);

    const char *filename_st = "file_77M_abc_st.txt";
    curl_mimepart *uploadfile_st = curl_mime_addpart(mimest);
    curl_mime_name(uploadfile_st, "file");
    curl_mime_filedata(uploadfile_st, filename_st);
    /*curl_mime_data_cb();*/

    curl_easy_setopt(easyst, CURLOPT_URL, url);
    curl_easy_setopt(easyst, CURLOPT_MIMEPOST, mimest);
    curl_easy_setopt(easyst, CURLOPT_ERRORBUFFER, errbuf);
    //curl_easy_setopt(easyzc, CURLOPT_VERBOSE, 1);

    result = curl_easy_perform(easyst);

    if (result == CURLE_OK) {
        printf("curl_easy_perform successful\n");
    } else {
        printf("curl_easy_perform returned other than CURLE_OK\n");
        printf("%s \n", errbuf);
    }

    free(errbuf);
    curl_mime_free(mimezc);
    curl_easy_cleanup(easyzc);
    curl_mime_free(mimest);
    curl_easy_cleanup(easyst);
    curl_global_cleanup();

    return 0;
}
