#include "lib/cfs/cfs.h"
#include "lib/cfs/cfs-impl.h"

int cfs_open(const char *name, int flags){
	return cfs_impl_open(name,flags);
}

void cfs_close(int fd){
	cfs_impl_close(fd);
}

int cfs_read(int fd, void *buf, unsigned int len){
	return cfs_impl_read(fd, buf, len);
}

int cfs_write(int fd, const void *buf, unsigned int len){
	return cfs_impl_write(fd, buf, len);
}

cfs_offset_t cfs_seek(int fd, cfs_offset_t offset, int whence){
	return cfs_impl_seek(fd, offset, whence);
}

int cfs_remove(const char *name){
	return cfs_impl_remove(name);
}

int cfs_opendir(struct cfs_dir *dirp, const char *name){
	return cfs_impl_opendir(dirp, name);
}

int cfs_readdir(struct cfs_dir *dirp, struct cfs_dirent *dirent){
	return cfs_impl_readdir(dirp, dirent);
}

void cfs_closedir(struct cfs_dir *dirp){
	cfs_impl_closedir(dirp);
}
