# How to mount Boot2Root Iso on file system.

#### Mount linux ISO on Macos ([SuperUser help](https://superuser.com/questions/1020741/mounting-a-linux-distro-iso-under-os-x-el-capitan)) :

```
➜ mkdir mount_boot2root
➜  secu_iso hdiutil attach -nomount <boot2root_iso>
/dev/disk4
➜  secu_iso mount -t cd9660 /dev/disk4 mount_boot2root
```

### However the filesystem is squashed (compressed & readonly) on an ISO.  

We need to decompress it to see whats in it :
 We are gonna use a tool that can deal with squahed file system  
**unsquashfs** is the tool for extracting data from squashed file systems. [documentation](http://www.tldp.org/HOWTO/html_single/SquashFS-HOWTO/#mksqoptions)

- To install : `brew install squashfs`
- Use it :
```
➜  mkdir fs_boot2root
➜  unsquashfs -l mount_boot2root/casper/filesystem.squashfs (list file system.)
➜  unsquashfs -f -d fs_boot2root/ mount_boot2root/casper/filesystem.squashfs (this one doesnt work.)
```
