package c_hash

import (
	"testing"
	"math/rand"
	"fmt"
	"log"

	ch "github.com/shinexia/algorithm-labs/distrib/c_hash"
)

func TestConsistentHash_AddNode(t *testing.T) {
	c := ch.New(4)
	nodes := make([]ch.Node, 10)
	for i := 0; i<len(nodes); i++ {
		nodes[i] = ch.NewNode(fmt.Sprintf("Node%02d", i))
	}
	c.Add(nodes...)

	{
		servers := make(map[string]int)
		for i := 0; i < 100000; i++ {
			n := rand.Intn(1000000000)
			key := fmt.Sprintf("%d", n)
			server := c.Pick(key)
			if server == nil {
				log.Fatalln("server is nil")
			}
			if v, ok := servers[server.Id()]; ok {
				servers[server.Id()] = v + 1
			} else {
				servers[server.Id()] = 1
			}
		}
		log.Printf("%v", servers)
	}

	{
		servers := make(map[string]int32)
		for i := 0; i < 1000000; i++ {
			n := rand.Intn(1000000000)
			key := fmt.Sprintf("%d", n)
			server := c.PickN(key, 2)
			for _, s := range server {
				if s == nil {
					log.Fatalln("name is nil", server)
				}
				if v, ok := servers[s.Id()]; ok {
					servers[s.Id()] = v + 1
				} else {
					servers[s.Id()] = 1
				}
			}
		}

		log.Printf("%v", servers)
	}
}
