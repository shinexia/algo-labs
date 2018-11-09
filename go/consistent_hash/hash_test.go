package consistent_hash

import (
	"testing"
	"math/rand"
	"fmt"
	"log"
)

func TestConsistentHash_AddNode(t *testing.T) {
	c := New(255)
	nodes := make([]Node, 10)
	for i := 0; i<len(nodes); i++ {
		nodes[i] = NewNode(fmt.Sprintf("Node%02d", i))
	}
	c.Add(nodes...)

	{
		servers := make(map[string]int)
		for i := 0; i < 10000; i++ {
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
		total := 0.0
		for _, s := range servers {
			total += float64(s)
		}
		for i := 0; i<len(nodes); i++ {
			key := nodes[i].Id()
			count := servers[key]
			log.Printf("%v - %.3f of %.2f", key, float64(count) / total, 1.0 / float64(len(nodes)))
		}
	}

	{
		servers := make(map[string]int32)
		for i := 0; i < 10000; i++ {
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
