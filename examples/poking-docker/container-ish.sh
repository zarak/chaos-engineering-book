#! /bin/bash
current_dir="$(dirname "${0}")"
FILESYSTEM_NAME=${1:-container-attempt-2}

# Step 1: execute our familiar new-filesystem script
bash $current_dir/new-filesystem.sh $FILESYSTEM_NAME
cd $FILESYSTEM_NAME

# Step 2: create a new pid namespace, and start a chrooted bash session
sudo unshare \
    --fork \
    --pid \
    --mount-proc \
    chroot . \
    /bin/bash -c "mkdir /proc && /bin/mount -t proc proc /proc && exec /bin/bash"
