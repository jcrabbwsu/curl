#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>

/*I/O*/
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

CURLcode curl_easy_perform_zc(struct Curl_easy *data);

/* custom write callback function */
size_t write_to_file(char *ptr, size_t size, size_t nmemb, void *filename)
{
    size_t check_size = size * nmemb;
    ssize_t write_size;

    int out_fd = open((char *) filename, O_WRONLY | O_APPEND | O_CREAT);

    if (out_fd < 0)
    {
        printf("couldn't open file\n");
        return 0;
    }

    write_size = write(out_fd, ptr, check_size);

    close(out_fd);

    if (write_size != check_size)
    {
        printf("size mismatch in write_to_file()\n");
        printf("expected %lu bytes \n", check_size);
        printf("wrote %ld bytes \n", write_size);
    }

    return write_size;
}


int main()
{
    setbuf(stdout, 0);

    CURL *easyzc = curl_easy_init();
    CURLcode result;
    int globalInit;
    char *errbuf = malloc(CURL_ERROR_SIZE);

    char *filename = "test_output_zc.txt";
    char *url = "http://pi.math.cornell.edu/~mec/2003-2004/cryptography/subs/frequencies.html";
    //char *url = "http://www.cplusplus.com/reference/cstdio/fprintf/";
    //char *url = "localhost:5000";

    globalInit = curl_global_init(CURL_GLOBAL_ALL);

    if (globalInit)
    {
        printf("curl_global_init failed \n");
        return 1;
    }

    curl_easy_setopt(easyzc, CURLOPT_URL, url);
    curl_easy_setopt(easyzc, CURLOPT_WRITEDATA, (void *) filename);
    curl_easy_setopt(easyzc, CURLOPT_ERRORBUFFER, errbuf);
    //curl_easy_setopt(easyzc, CURLOPT_VERBOSE, 1);


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


    filename = "test_output_st.txt";
    curl_easy_reset(easyzc);
    curl_easy_setopt(easyzc, CURLOPT_URL, url);
    curl_easy_setopt(easyzc, CURLOPT_WRITEDATA, (void *) filename);
    curl_easy_setopt(easyzc, CURLOPT_WRITEFUNCTION, write_to_file);
    curl_easy_setopt(easyzc, CURLOPT_ERRORBUFFER, errbuf);

    result = curl_easy_perform(easyzc);

    if (result == CURLE_OK)
    {
        printf("curl_easy_perform successful\n");
    }
    else
    {
        printf("curl_easy_perform returned other than CURLE_OK\n");
        printf("%s \n", errbuf);
    }

    free(errbuf);
    curl_easy_cleanup(easyzc);
    curl_global_cleanup();

    return 0;
}
