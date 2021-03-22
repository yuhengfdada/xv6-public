struct buf { // one buffer stands for a block. Many buffers form a buffer cache.
  int flags; // B_VALID or B_DIRTY
  uint dev; // device
  uint blockno;
  struct sleeplock lock;
  uint refcnt;
  struct buf *prev; // LRU cache list
  struct buf *next;
  struct buf *qnext; // disk queue
  uchar data[BSIZE]; // in xv6, BSIZE is equal to sector size (512 bytes). In real world BSIZE is often a multiple of 512 bytes.
};
#define B_VALID 0x2  // buffer has been read from disk
#define B_DIRTY 0x4  // buffer needs to be written to disk

