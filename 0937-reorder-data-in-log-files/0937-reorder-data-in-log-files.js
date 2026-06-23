/**
 * @param {string[]} logs
 * @return {string[]}
 */
var reorderLogFiles = function(logs) {
    const letterLogs = [];
    const digitLogs = [];

    for (const log of logs) {
        const idx = log.indexOf(' ');
        const identifier = log.substring(0, idx);
        const content = log.substring(idx + 1);

        if (!isNaN(content[0])) {
            digitLogs.push(log);
        } else {
            letterLogs.push([identifier, content, log]);
        }
    }

    letterLogs.sort((a, b) => {
        if (a[1] === b[1]) {
            return a[0].localeCompare(b[0]);
        }
        return a[1].localeCompare(b[1]);
    });

    return [
        ...letterLogs.map(log => log[2]),
        ...digitLogs
    ];
};