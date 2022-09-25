FROM alpine:3.15.6

RUN apk update && apk upgrade &&\
    apk add mysql mysql-client openrc &&\
    openrc && touch /run/openrc/softlevel
    #adduser mariedb --disabled-password && su mariedb
    # mysql-client

VOLUME [ “/sys/fs/cgroup” ]

COPY ./mariadb.cnf /etc/mysql/
COPY ./dbinit /

#RUN rm -f /dbinit
