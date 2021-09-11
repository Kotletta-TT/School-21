FROM debian:buster

EXPOSE 80
EXPOSE 443

ENV MYSQL_ROOT=root
ENV MYSQL_PASS=p@ssw0rd
ENV MYSQL_DBNAME=wordpress
ENV WP_DBUSER=wpuser
ENV WP_DBPASS=p@ssw0rd
ENV WEB_DIR=/var/www/
ENV FULL_WEB=${WEB_DIR}wordpress
ENV NGINX_CONF_DIR=/etc/nginx/sites-available

RUN apt-get update -qq  \
    &&                  \
    apt-get install -qq \
    nginx               \
    mariadb-server      \
    mariadb-client      \
    curl                \
    php-fpm             \
    php-mysql           \
    php-cgi             \
    php-curl            \
    php-common          \
    php-pear            \
    php-mbstring        \
    php-zip             \
    php-net-socket      \
    php-gd              \
    php-xml             \
    php-xmlrpc          \
    php-gettext         \
    php-bcmath          \
    vim                 \
    unzip               \
    -y

WORKDIR /tmp

RUN curl -Os https://wordpress.org/latest.tar.gz                                                \
&& tar xf latest.tar.gz                                                                         \
&& mv wordpress ${WEB_DIR}                                                                      \
&& curl -Os https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.zip    \
&& unzip phpMyAdmin-5.1.0-all-languages.zip                                                     \
&& mkdir phpmyadmin                                                                             \
&& mv phpMyAdmin-5.1.0-all-languages/* /tmp/phpmyadmin/                                         \
&& cp -R phpmyadmin ${FULL_WEB}                                                                 \
&& rm -f latest.tar.gz phpMyAdmin-5.1.0-all-languages.zip


WORKDIR $FULL_WEB
RUN mv wp-config-sample.php wp-config.php                           \
&& sed -i "s/database_name_here/$MYSQL_DBNAME/g" wp-config.php      \
&& sed -i "s/username_here/$WP_DBUSER/g" wp-config.php              \
&& sed -i "s/password_here/$WP_DBPASS/g" wp-config.php              \
&& chown -R www-data $FULL_WEB                                      \
&& chmod -R 755 $FULL_WEB

COPY srcs/nginx/wp $NGINX_CONF_DIR
RUN ln -s ${NGINX_CONF_DIR}/wp /etc/nginx/sites-enabled/           \
&& rm -f ${NGINX_CONF_DIR}/default                                 \
&& rm -f /etc/nginx/sites-enabled/default

WORKDIR /etc/nginx/ssl
RUN openssl req -newkey rsa:4096    \
            -x509                   \
            -sha256                 \
            -days 365               \
            -nodes                  \
            -out ft-server.crt      \
            -keyout ft-server.key   \
            -subj "/C=RU/ST=FLorida/L=Sochi/O=PowerMain/OU=Managment World/CN=localhost"

WORKDIR /usr/local/ft_server
COPY srcs/start.sh .

RUN chown root start.sh \
&& chmod 755 start.sh

CMD ["./start.sh"]
