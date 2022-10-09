# highload_webserver

MyServer
```
docker build . -t kostinichwebserver
docker run --rm -p 80:4000 kostinichwebserver
ab -n 10000 -c 10 127.0.0.1:80/httptest/wikipedia_russia.html 

Server Software:        my_http_server
Server Hostname:        127.0.0.1
Server Port:            80

Document Path:          /httptest/wikipedia_russia.html
Document Length:        954824 bytes

Concurrency Level:      10
Time taken for tests:   27.033 seconds
Complete requests:      10000
Failed requests:        0
Total transferred:      9549850000 bytes
HTML transferred:       9548240000 bytes
Requests per second:    369.91 [#/sec] (mean)
Time per request:       27.033 [ms] (mean)
Time per request:       2.703 [ms] (mean, across all concurrent requests)
Transfer rate:          344983.19 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.9      0      24
Processing:     3   26  91.7     16    1161
Waiting:        0   22  91.3     12    1158
Total:          3   27  91.7     17    1161

Percentage of the requests served within a certain time (ms)
  50%     17
  66%     20
  75%     23
  80%     25
  90%     31
  95%     37
  98%     47
  99%    158
 100%   1161 (longest request)

```
Nginx sever
```
docker build . -t nginxwebserver -f nginx.Dockerfile
docker run --rm -p 80:80 nginxwebserver
ab -n 10000 -c 10 127.0.0.1:80/httptest/wikipedia_russia.html 

Server Software:        nginx/1.23.1
Server Hostname:        127.0.0.1
Server Port:            80

Document Path:          /httptest/wikipedia_russia.html
Document Length:        153 bytes

Concurrency Level:      10
Time taken for tests:   3.711 seconds
Complete requests:      10000
Failed requests:        0
Non-2xx responses:      10000
Total transferred:      3030000 bytes
HTML transferred:       1530000 bytes
Requests per second:    2694.68 [#/sec] (mean)
Time per request:       3.711 [ms] (mean)
Time per request:       0.371 [ms] (mean, across all concurrent requests)
Transfer rate:          797.35 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    1   1.0      0      15
Processing:     0    3  18.5      2     519
Waiting:        0    3  18.4      1     513
Total:          0    4  18.5      2     520
WARNING: The median and mean for the initial connection time are not within a normal deviation
        These results are probably not that reliable.

Percentage of the requests served within a certain time (ms)
  50%      2
  66%      3
  75%      3
  80%      4
  90%      5
  95%      7
  98%     10
  99%     14
 100%    520 (longest request)
```
Тестирование количества обрабатываемых запросов при ограничении CPU

```

ab -n 10000 -c 256 127.0.0.1:4000/httptest/wikipedia_russia.html 
ab -n 10000 -c 256 127.0.0.1:80/wikipedia_russia.html 

```

|Count of processes | My Server requests count|Nginx requests count |
|--|--|--|
1 | 469 | 2148
2 | 643 | 2302
4 | 762 | 2310