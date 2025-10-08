var avoidFlood = function(rains) {
    const last = new Map();
    const q = [];
    const res = [];

    for (let i = 0; i < rains.length; i++) {
        const lake = rains[i];
        if (lake !== 0) {
            if (last.has(lake)) {
                let found = false;
                const temp = [];
                while (q.length > 0) {
                    const j = q.shift();
                    if (!found && j > last.get(lake)) {
                        res[j] = lake;
                        found = true;
                    } else {
                        temp.push(j);
                    }
                }
                if (!found) return [];
                q.push(...temp);
            }
            res.push(-1);
            last.set(lake, i);
        } else {
            res.push(1);
            q.push(i);
        }
    }

    return res;
};
