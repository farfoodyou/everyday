

ping google.com 

fsdisk -l

cfdisk

// 这里创建磁盘分区

mkfs.ext4 /dev/sda1

mkfs.ext4 /dev/sda3 

mkfs.vfat /dev/sda4   //esp

mkswap /dev/sda2

swapon /dev/sda2 

```
mount /dev/sda1 /mnt
mkdir /mnt/home
mount /dev/sda3 /mnt/home
mount /dev/sda4 /mnt/boot    #挂载esp到/boot
```
记得删除 /etc/pacman.d/mirrorlist 下的其他镜像站, 

仅保留清华的, 速度非常非常快

pacstrap /mnt base base-devel xorg

genfstab /mnt>> /mnt/etc/fstab 

arch-chroot /mnt /bin/bash

nano /etc/locale.gen

locale-gen
```
nano /etc/locale.conf 
LANG=en_US.UTF-8
```

ls /usr/share/zoneinfo

ln –s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime

```
hwclock --systohc -l   //当地时间
hwclock --systohc --utc  //当做utc
```

nano /etc/hostname

systemctl enable dhcpcd

//安装引导  使用了efi的情况
grub-install --efi-directory=/boot --bootloader-id=grub
//生成引导配置
grub-mkconfig -o /boot/grub/grub.cfg

pacman -S grub efibootmgr
grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=grub

err:
failed to connect to lvmetad. failing back to device scanning
编辑/etc/lvm/lvm.conf这个文件，找到use_lvmetad = 1将1修改为0，保存，重新配置grub

not initialized in udev database even

最后在装硬盘引导这里失败了, 真坑爹

12月19号:
virtualbox 设置打开efi 之后
usb启动会失败, 用grub手动启动只有
grub-mkconfig一下

获取 IP 地址 使用 DHCP：
`ip a`
`dhcpcd enp0s3`

