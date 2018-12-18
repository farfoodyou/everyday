# GPG

## init
gpg --help
gpg --gen-key
gpg --list-keys

## encode decode
gpg -r huyalyu -e README.md
gpg -o README.de.md -d README.md.gpg
## sign
gpg --sign demo.txt
gpg --clearsign demo.txt
gpg --detach-sign demo.txt
gpg --armor --detach-sign demo.txt
gpg --verify demo.txt.asc demo.txt

## export import
gpg --armor --output public-key.txt --export [用户ID]
gpg --armor --output private-key.txt --export-secret-keys

gpg --import [密钥文件]

## 
gpg --send-keys [用户ID] --keyserver hkp://subkeys.pgp.net
gpg --fingerprint [用户ID]

gpg --keyserver hkp://subkeys.pgp.net --search-keys [用户ID]

