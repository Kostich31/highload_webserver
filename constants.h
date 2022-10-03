#pragma once
#include <string>

const std::string configPath = "../httpd.conf";

const int MAX_MESSAGE_SIZE = 10000;
const int DEFAULT_CODE = 0;
enum supportedCodes
{
    OK = 200,
    FORBIDDEN = 403,
    NOT_FOUND = 404,
    METHOD_NOT_ALLOWED = 405
};

struct Config
{
    int threadsLimit;
    std::string documentRoot;
};

struct HTTPRequest
{
    std::string method;
    std::string path;
    std::string protocol;
};

struct HTTPResponse
{
    std::string protocol = "HTTP/1.1";
    int code = DEFAULT_CODE;
    std::string server = "my_http_server";
    int contentLength;
    std::string data;
    std::string contentType;
    std::string connection = "close";
};
