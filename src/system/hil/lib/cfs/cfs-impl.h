#ifndef __CFS_IMPL_H__
#define __CFS_IMPL_H__

CCIF int cfs_impl_open(const char *name, int flags);

CCIF void cfs_impl_close(int fd);

CCIF int cfs_impl_read(int fd, void *buf, unsigned int len);

CCIF int cfs_impl_write(int fd, const void *buf, unsigned int len);

CCIF cfs_offset_t cfs_impl_seek(int fd, cfs_offset_t offset, int whence);

CCIF int cfs_impl_remove(const char *name);

CCIF int cfs_impl_opendir(struct cfs_dir *dirp, const char *name);

CCIF int cfs_impl_readdir(struct cfs_dir *dirp, struct cfs_dirent *dirent);

CCIF void cfs_impl_closedir(struct cfs_dir *dirp);

#endif /* __CFS_IMPL_H__ */
