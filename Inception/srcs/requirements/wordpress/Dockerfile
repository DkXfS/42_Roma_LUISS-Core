FROM alpine:3.15.6

RUN apk update && apk upgrade &&\
	apk add php7 php7-fpm php7-opcache wget

RUN wget https://wordpress.org/latest.tar.gz -P ./workingdir &&\
	tar -xzf ./workingdir/latest.tar.gz -C ./srv/ &&\
	rm -rf ./workingdir