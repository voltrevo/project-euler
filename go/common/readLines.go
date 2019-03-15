package common

import (
    "io"
)

func ReadLines(reader io.Reader, cb func(int, string)) error {

    buf := [262144]byte{} // 256kb buffer
    bufs := buf[:]
    partialLine := ""
    lineNo := 0

    for {
        n, err := reader.Read(bufs)

        if err != nil {
            if err != io.EOF {
                return err
            }

            // err == io.EOF
            break
        }

        pos := 0
        i := 0

        for ; i != n; i++ {
            if bufs[i] == '\n' {
                lineNo++
                cb(lineNo, partialLine + string(bufs[pos:i]))
                partialLine = ""
                pos = i + 1
                i++
                break
            }
        }

        for ; i != n; i++ {
            if bufs[i] == '\n' {
                lineNo++
                cb(lineNo, string(bufs[pos:i]))
                pos = i + 1
            }
        }

        partialLine += string(bufs[pos:i])
    }

    return nil
}
