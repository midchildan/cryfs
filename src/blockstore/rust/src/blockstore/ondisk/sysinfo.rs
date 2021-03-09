// mod linux {
//     use libc::statvfs;

//     /* convert a path to a NUL-terminated Vec<u8> suitable for use with C functions */
//     #[cfg(not(any(target_os = "windows", target_os = "unknown", target_arch = "wasm32")))]
//     pub fn to_cpath(path: &Path) -> Vec<u8> {
//         let path_os: &OsStr = path.as_ref();
//         let mut cpath = path_os.as_bytes().to_vec();
//         cpath.push(0);
//         cpath
//     }

//     pub fn get_available_disk_space(path: &Path) -> u64 {
//         let mut stat: statvfs = mem::zeroed();
//         let mount_point_cpath = to_cpath(&path);
//         let success = unsafe {
//             statvfs(mount_point_cpath.as_ptr() as *const _, &mut stat) == 0;
//         };
//         assert_eq!(0, success, "Failed to call statvfs");
//         u64::from(stat.f_bsize) * u64::from(stat.f_bavail)
//     }
// }
