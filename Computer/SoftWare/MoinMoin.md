sudo docker run -d -p 443:443 -p 80:80 -v /opt/moinmoin-data:/usr/local/share/moin/data --name my_wiki olavgg/moinmoin-wiki

docker exec -it 775c7c9ee1e1 /bin/bash

构建本地镜像
docker build -t h/moinmoin-wiki .


docker image inspect --format='{{.RepoTags}} {{.Id}} {{.Parent}}' $(docker image ls -q --filter since=xxxxxx)

docker rmi $(docker images -q) -f

##### ACLS
http://www.cnblogs.com/simonw/archive/2006/12/09/586923.html

