#!/bin/bash

echo "Setting Database"

service mysql start

mariadb --user="${MYSQL_ROOT}" --password="${MYSQL_PASS}" --execute="CREATE DATABASE ${MYSQL_DBNAME} DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;"
mariadb --user="${MYSQL_ROOT}" --password="${MYSQL_PASS}" --execute="GRANT ALL ON ${MYSQL_DBNAME}.* TO '${WP_DBUSER}'@'localhost' IDENTIFIED BY '${WP_DBPASS}';"
mariadb --user="${MYSQL_ROOT}" --password="${MYSQL_PASS}" --execute="FLUSH PRIVILEGES;"

echo "Start PHP-FPM"

service php7.3-fpm start

service nginx start

while true; do
sleep 1
done